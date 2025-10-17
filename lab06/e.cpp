#include <iostream>
using namespace std;

void quicksort(int l, int r, int* arr) {
    int i = l, j = r;

    int p = arr[(l+r)/2];

    while (i < j)
    {
        while (arr[i] > p)
        {
            i++;
        }
        

        while (arr[j] < p)
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
        quicksort(l, j, arr);
    }

    if (i < r)
    {
        quicksort(i, r, arr);
    }
        
}



int main()  {
    int n, m;
    cin >> n >> m; 
    int arr[n][m];
    int arr_copy[m][n];


    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) {
            int number; cin >> number;
            arr[i][j] = number;
        }
    }


    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr_copy[i][j] = arr[j][i];
        }
    }


    for (int i = 0; i < m; i++)
    {
        quicksort(0, n-1, arr_copy[i]);
    }
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr_copy[j][i] << " ";
        }
        cout << endl;
        
    }
    

    
    return 0;
}