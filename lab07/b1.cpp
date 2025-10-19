#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right) {

    int n1 = mid-left+1, n2 = right - mid;
    
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left+i];
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[(mid+1)+i];
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

void mergesort(vector<int> &arr, int left, int right) {
    if (left < right)
    {
        int mid = left + (right-left)/2;

        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
    
}



int main() {
    int n;
    cin >> n;

    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x; arr.push_back(x);
    }

    int m; cin >> m;

    for (int j = 0; j < m; j++)
    {
        int x; cin >> x; arr.push_back(x);
    }

    mergesort(arr, 0, arr.size()-1);


    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    
    
    

    return 0;
}