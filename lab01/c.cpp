#include <iostream>
#include <stack>
using namespace std;
int main() {

    stack<char> k1, k2;

    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != '#')
        {
            k1.push(s1[i]);
        }
        else
        {
            k1.pop();
        }
    }
    
    for (int i = 0; i < s2.size(); i++)
    {
        if (s2[i] != '#')
        {
            k2.push(s2[i]);
        }
        else
        {
            k2.pop();
        }
    }



    if (k1 == k2)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    
    
    return 0;
}