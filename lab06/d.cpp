#include <iostream>
#include <vector>
using namespace std;

struct date
{
    int day, month, year; 
};


bool lessDate(date a, date b) {
    if(a.year != b.year) return a.year < b.year;
    if(a.month != b.month) return a.month < b.month;
    return a.day < b.day;
}



void quicksort(int l, int r, vector<date> &arr) {
    int i = l, j = r;

    date p = arr[(l+r)/2];


    
    while (i < j)
    {

        while (lessDate(arr[i], p))
        {
            i++;
        }
        
        while (lessDate(p, arr[j]))
        {
            j--;
        } 
        

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }        
    }



    if (l < j)
    {
        quicksort(l, j, arr);
    }

    if (i < r)
    {
        quicksort(i, r, arr);
    }

    
}





int main() {

    date p;
    
    int n; cin >> n;
    vector<date> arr;

    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;

        int d = (s[0] - '0') * 10 + (s[1]-'0');
        int m = (s[3] - '0') * 10 + (s[4]-'0');
        int y = (s[6]-'0')*1000 + (s[7]-'0')*100 + (s[8]-'0')*10 + (s[9]-'0');
        
        date p;
        p.day = d; p.month = m; p.year = y;

        arr.push_back(p); 
    }

    quicksort(0, arr.size()-1, arr);

    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i].day < 10 && arr[i].month < 10) {
            cout <<"0"<< arr[i].day << "-0" << arr[i].month << "-" << arr[i].year << endl;
        }

        else if(arr[i].day < 10) {
            cout <<"0"<< arr[i].day <<"-" << arr[i].month << "-" << arr[i].year << endl;
        }

        else if(arr[i].month < 10) {
            cout << arr[i].day << "-0" << arr[i].month << "-" << arr[i].year << endl;
        }
        
        else {
            cout << arr[i].day << "-" << arr[i].month << "-" << arr[i].year << endl;
        }

    }
    
    
    
    return 0;
}