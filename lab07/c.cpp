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



void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid-left+1, n2 = right - mid;
    
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left+i];
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[(mid+1) + i];
    }


    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
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
        arr[k] = L[i];
        i++; k++;
    }
    

    while (j < n2)
    {
        arr[k] = R[j];
        j++; k++;
    }
    
    
}


void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right)
    {
        int mid = left + (right-left)/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
    
}



int main() {

    int n, m; cin >> n >> m;

    vector<int> arr1, arr2;



    for (int i = 0; i < n; i++)
    {
        int x; cin >> x; arr1.push_back(x);
    }

    for (int i = 0; i < m; i++)
    {
        int x; cin >> x; arr2.push_back(x);
    }


    mergeSort(arr1, 0, arr1.size()-1);
    mergeSort(arr2, 0, arr2.size()-1);

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