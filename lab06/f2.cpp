#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct student
{
    string name, surname;
    double gpa;
};


bool cmp(student number1, student number2) {
    if (number1.gpa != number2.gpa) return number1.gpa < number2.gpa;
    if (number1.surname != number2.surname) return number1.surname < number2.surname;
    return number1.name < number2.name;
    
}


void quicksort(int l, int r, vector<student> &gpa) {

    student p = gpa[(l+r)/2];

    int i = l, j = r;

    while (i < j)
    {
        while (cmp(gpa[i], p))
        {
            i++;
        }

        while (cmp(p, gpa[j]))
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

    vector<student> arr;

    long long n; cin >> n;

    for(int i = 0; i < n; i++){
        
        string surname, name; int m; 
        cin >> surname >> name >> m;

        long long sum_of_credits = 0; double sum_of_gpa = 0;
        for(int j = 1; j <= m; j++){
            string s; int x;
            cin >> s >> x;
            if(s == "A+") sum_of_gpa += (4.0 * x);
            if(s == "A") sum_of_gpa += (3.75 * x);
            if(s == "B+") sum_of_gpa += (3.5 * x);
            if(s == "B") sum_of_gpa += (3.0 * x);
            if(s == "C+") sum_of_gpa += (2.5 * x);
            if(s == "C") sum_of_gpa += (2.0 * x);
            if(s == "D+") sum_of_gpa += (1.5 * x);
            if(s == "D") sum_of_gpa += (1.0 * x);
            if(s == "F") sum_of_gpa += (0 * x);
            
            sum_of_credits += x;
        }
        double gpa = sum_of_gpa/double(sum_of_credits);

        student fio;
        fio.name = name; fio.surname = surname; fio.gpa = gpa;
        arr.push_back(fio);
    }



    quicksort(0, arr.size()-1, arr);

    cout << fixed << setprecision(3);
    for (int i = 0; i < arr.size(); i++)
    {
        cout.precision(3);
        cout << arr[i].surname << " " << arr[i].name << " " << fixed << arr[i].gpa << endl;
    }
    
    

    return 0;
}