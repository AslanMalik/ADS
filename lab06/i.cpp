#include <iostream>
#include <vector>
using namespace std;

void quicksort(int l, int r, vector<char> &arr) {
    int i = l, j = r;
    int p = arr[(l+r)/2];

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
    vector<char> arr;

    string s; cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        arr.push_back(s[i]);
    }

    quicksort(0, arr.size()-1, arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
    }
    
    
    return 0;
}