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


void merge(vector<student> &arr, int left, int mid, int right) {
    int n1 = mid+1-left, n2 = right - mid;

    vector<student> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }


    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (cmp(L[i] ,R[j]))
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }




    while (i < n1)
    {
        arr[k] = L[i]; i++; k++;
    }
    
    
    while (j < n2)
    {
        arr[k] = R[j]; j++; k++;
    }
    
}



void megresort(vector<student> &arr, int left, int right) {
    if (left < right)
    {
        int mid = left + (right-left)/2;

        megresort(arr, left, mid);
        megresort(arr, mid+1, right);

        merge(arr, left, mid, right);
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



    megresort(arr, 0, arr.size()-1);

    cout << fixed << setprecision(3);
    for (int i = 0; i < arr.size(); i++)
    {
        cout.precision(3);
        cout << arr[i].surname << " " << arr[i].name << " " << fixed << arr[i].gpa << endl;
    }
    
    

    return 0;
}