#include <iostream>
#include <vector>
using namespace std;


bool cmp(pair<vector<int>, int> &arr1, pair<vector<int>, int> &arr2) {
    if (arr1.second != arr2.second) return arr1.second < arr2.second;
    
    for (int i = 0; i < arr1.first.size(); i++)
    {
        if (arr1.first[i] != arr2.first[i]) return arr1.first[i] > arr2.first[i];
    }

    return false;
    
}


void merge(vector<pair<vector<int>, int>> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<pair<vector<int>, int>> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[(mid+1) + j];
    }


    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (cmp(L[i], R[j]))
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


void mergeSort(vector<pair<vector<int>, int>> &arr , int left, int right) {
    if (left < right)
    {
        int mid = left + (right-left)/2;

        mergeSort(arr,left, mid);
        mergeSort(arr,mid+1, right);


        merge(arr, left, mid, right);
    }
    
}

int main() {

    vector<pair<vector<int>, int>> arr;

    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int total = 0;
        vector<int> arr_sub;
        for (int j = 0; j < m; j++)
        {
            int number; cin >> number;
            arr_sub.push_back(number);
            total += number;
        }

        arr.push_back(make_pair(arr_sub, total));
    }

    mergeSort(arr, 0, arr.size()-1);
    
    for (int i = arr.size()-1; i >= 0; i--)
    {
        for (int j = 0; j < arr[i].first.size(); j++)
        {
            cout << arr[i].first[j] << " ";
        }
        cout << endl;
        
    }
    

    return 0;
}