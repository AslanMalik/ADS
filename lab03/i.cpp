#include <iostream>
#include <vector>
using namespace std;

bool binary_search(vector<int> &arr, int find){
    int left = 0, right = arr.size()-1;

    while (left <= right)
    {
        int mid = (left+right)/2;

        if (arr[mid] == find)
        {
            return true;
        }

        else if (arr[mid] > find)
        {
            right = mid -1;
        }

        else
        {
            left = mid +1;
        }
        
    }

    return false;
    
}




int main() {
    vector<int> arr;


    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        arr.push_back(k);
    }


    int find;
    cin >>find;

    if (binary_search(arr, find))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    
    
    return 0;
}