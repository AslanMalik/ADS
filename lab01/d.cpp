#include <iostream>
#include <stack>
using namespace std;
int main() {
    string s1;
    cin >> s1;
    stack<char> s11;
    bool flag = true;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s11.empty())
        {
            s11.push(s1[i]);
        }
        else
        {
            if (s11.top() == s1[i])
            {
                s11.pop();
            }
            else
            {
                s11.push(s1[i]);
            }
        }
    }
    

    if (s11.empty())
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    
    


    return 0;
}