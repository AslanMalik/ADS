#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

    vector<int> arr;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }


    int k;
    cin >> k;



    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = abs(arr[i] - k);
    }


    int min_value = 1000000;


    for ( int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < min_value)
        {
            min_value = arr[i];
        }
        
    }
    


    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == min_value)
        {
            cout << i;
            break;
        }
        
    }
    
    

    




    return 0;
}