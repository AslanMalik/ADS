#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int target) {
    int left = 0, right = arr.size()-1;
    
    while (left <= right)
    {
        int mid = left +  (right-left)/2;

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] > target)
        {
            right = mid-1;
        }
        else
        {
            left = mid + 1;
        }        
    }
    return -1;
    
}


void quicksort(int l, int r, vector<int> &arr) {

    int p = arr[(l+r)/2];


    int i = l, j = r;
    while (i < j)
    {
        while (arr[i] < p)
        {
            i++;
        }

        while (arr[j] > p)
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

    if (i < r)
    {
        quicksort(i, r, arr);
    }

    if (l < j)
    {
        quicksort(l, j, arr);
    }
        
}





int main() {
    int n, m; cin >> n >> m;

    if(n == 0 || m == 0) return 0;

    vector<int> arr1, arr2;

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x; arr1.push_back(x);
    }
    
    for (int i = 0; i < m; i++)
    {
        int x; cin >> x; arr2.push_back(x);
    }


    quicksort(0, n-1, arr1);
    quicksort(0, m-1, arr2);


    if (arr1.size() > arr2.size())
    {
        for (int i = 0; i < arr2.size(); i++)
        {
            int flag = binarySearch(arr1, arr2[i]);

            if (flag != -1)
            {
                cout << arr2[i] << " ";
                arr1.erase(arr1.begin()+flag);
            }
        }
        
    }

    else
    {
        for (int i = 0; i < arr1.size(); i++)
        {
            int flag = binarySearch(arr2, arr1[i]);

            if (flag != -1)
            {
                cout << arr1[i] << " ";
                arr2.erase(arr2.begin()+flag);
            }
        }
    }
    
    



    return 0;
}