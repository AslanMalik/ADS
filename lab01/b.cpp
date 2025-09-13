#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> massive(n);
    stack<int> lessmore;

    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }


    for (int i = 0; i < arr.size(); i++)
    {
        while (!lessmore.empty() && lessmore.top() > arr[i])
        {
            lessmore.pop();
        }

        if (lessmore.empty())
        {
            massive[i] = -1;
        }
        else
        {
            massive[i] = lessmore.top();
        }
        
        lessmore.push(arr[i]);
        
    }
    



    for (int i = 0; i < massive.size(); i++)
    {
        cout << massive[i] << " ";
    }
        


    return 0;
}