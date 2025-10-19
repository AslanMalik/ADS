#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> arr1;
    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x; arr1.push_back(x);
    }
    
    int m; cin >> m;
    vector<int> arr2;
    vector<int> arr3;

    for (int i = 0; i < m; i++)
    {
        int x; cin >> x; arr2.push_back(x);
    }

    int min_len = min(arr1.size(), arr2.size());

    int l = 0, k = 0;
    for (int i = 0; i < min_len; i++)
    {
        if (arr1[l] < arr2[k])
        {
            arr3.push_back(arr1[l]);
            l++;
        }
        else
        {
            arr3.push_back(arr2[k]);
            k++;
        }
    }

    while (l < arr1.size())
    {
        arr3.push_back(arr1[l]);
        l++;
    }

    while (k < arr2.size())
    {
        arr3.push_back(arr2[k]);
        k++;
    }
    
    

    for (int i = 0; i < arr3.size(); i++)
    {
        cout << arr3[i] << " ";
    }
    
    
    

    return 0;
}