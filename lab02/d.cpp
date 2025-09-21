#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    map<int, int> moda;


    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        moda[t]++;
    }

    map<int, int>::iterator it;
    int max_number = 0;

    for (it = moda.begin(); it != moda.end(); ++it)
    {
        if (it->second > max_number)
        {
            max_number = it->second;
        }
    }

    vector<int> arr;
    

    for ( it = moda.begin(); it != moda.end(); ++it)
    {
        if (max_number == it->second)
        {
            arr.push_back(it->first);   
        }
    }


    for (int i = arr.size()-1; i >= 0; --i)
    {
        cout << arr[i] << " ";
    }
    
    
    
    


    return 0;
}