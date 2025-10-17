#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);


    
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left+i];   
    }

    for (int i = 0; i < i; i++)
    {
        R[i] = arr[mid+]
    }
    
    
}


void mergeSort(vector<pair<vector<int>, int>> &arr , int left, int right) {
    if (left < right)
    {
        int mid = left + (right-left)/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);


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
    


    return 0;
}