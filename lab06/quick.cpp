#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

void quicksort(int l, int r) {
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
    
    if (l < j)
    {
        quicksort(l ,j);
    }

    
    if (i < r)
    {
        quicksort(i, r);
    }
    
}

int main() {

    int n; cin >> n;


    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        arr.push_back(x);
    }


    
    quicksort(0, arr.size()-1);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}