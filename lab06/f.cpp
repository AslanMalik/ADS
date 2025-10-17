#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void quicksort(int l, int r, vector<pair<pair<string,string>, double>> &gpa) {
    if (l >= r) return; 

    pair<pair<string,string>, double> &p = gpa[(l+r)/2];

    int i = l, j = r;

    while (i <= j)
    {
        while (gpa[i].second < p.second || gpa[i].second == p.second && gpa[i].first.first < p.first.first || gpa[i].second == p.second && gpa[i].first.first == p.first.first && gpa[i].first.second < p.first.second)
        {
            i++;
        }

        while (gpa[j].second > p.second || gpa[j].second == p.second && gpa[j].first.first > p.first.first || gpa[j].second == p.second && gpa[j].first.first == p.first.first && gpa[j].first.second > p.first.second)
        {
            j--;
        }

        if (i<=j)
        {
            swap(gpa[i], gpa[j]);
            i++;
            j--;
        }
                
    }

    if (i < r)
    {
        quicksort(i, r, gpa);
    }

    if (l < j)
    {
        quicksort(l, j, gpa);
    }
    
}


int main() {
    int n; cin >> n;

    vector<pair<pair<string,string>, double>> gpa;

    for (int i = 0; i < n; i++)
    {
        string name, surname; int number;
        cin >> name >> surname >> number; 

        // float overall = 0;
        double sum_credit = 0, gc = 0;

        for (int j = 0; j < number; j++)
        {
            string grade; int credit; cin >> grade >> credit;
            
            if (grade == "A+")
            {
                gc = gc + (4.0*credit);
                sum_credit+=credit;
            }
            else if (grade == "A")
            {
                gc = gc + (3.75*credit);
                sum_credit+=credit;

            }
            else if (grade == "B+")
            {
                gc = gc + (3.5*credit);
                sum_credit+=credit;
            }
            else if (grade == "B")
            {
                gc = gc + (3.0*credit);
                sum_credit+=credit;
            }
            else if (grade == "C+")
            {
                gc = gc + (2.5*credit);
                sum_credit+=credit;
            }
            else if (grade == "C")
            {
                gc = gc + (2.0*credit);
                sum_credit+=credit;
            }
            else if (grade == "D+")
            {
                gc = gc + (1.5*credit);
                sum_credit+=credit;
            }
            else if (grade == "D")
            {
                gc = gc+(1.0*credit);
                sum_credit+=credit;
            }
            else
            {
                gc = gc+(0*credit);
                sum_credit+=credit;
            }
                
        }

        double overall;

        if (sum_credit > 0.0)
        {
            overall = gc/sum_credit;
        }
        else
        {
            overall = 0.0;
        }
        
        

        gpa.push_back(make_pair(make_pair(surname, name),overall));
        
    }

    quicksort(0, gpa.size()-1, gpa);

    cout << fixed << setprecision(3);
    for (int i = 0; i < gpa.size(); i++)
    {
        cout << gpa[i].first.second << " " << gpa[i].first.first << " " <<  gpa[i].second << endl;
    }
    
    
    return 0;
}


// A+	4.00
// A	3.75
// B+	3.50
// B	3.00
// C+	2.50
// C	2.00
// D+	1.50
// D	1.00
// F	0
