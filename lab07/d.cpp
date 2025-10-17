#include <iostream>
using namespace std;

struct student
{
    string lastname, firstname;
    double gpa;
};


int main() {


    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        int number; string lastname, firstname;
        
        int total_credit = 0;
        double 

        cin >> number >> lastname >> firstname;

        for (int j = 0; j < number; j++)
        {
            int credit; string grade; cin >> credit >> grade;
            total_credit += credit;
        }
        
    }
    


    return 0;
}