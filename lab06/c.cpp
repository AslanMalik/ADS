#include <iostream>
#include <vector>
using namespace std;

void quicksort(int l, int r, vector<int> &arr) {
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

    if (j > l)
    {
        quicksort(l, j, arr);
    }
    
}


int main() {

    vector<int> arr;

    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x; arr.push_back(x);
    }

    quicksort(0, arr.size()-1, arr);

    vector<pair<int, int>> absolute;

    absolute.push_back(make_pair(arr[0], arr[1]));

    for (int i = 1; i < n-1; i++)
    {
        int first = arr[i], second = arr[i+1];

        if (absolute.size() == 0)
        {
            absolute.push_back(make_pair(first, second));
        }

        while (!absolute.empty())
        {
            if (absolute[absolute.size()-1].second - absolute[absolute.size()-1].first > second-first )
            {
                absolute.pop_back();
            }

            if ((absolute[absolute.size()-1].second - absolute[absolute.size()-1].first == second-first))
            {
                absolute.push_back(make_pair(first, second));
                break;
            }

            if (absolute[absolute.size()-1].second - absolute[absolute.size()-1].first < second-first )
            {
                break;
            }
        }

        
        if (absolute.size() == 0)
        {
            absolute.push_back(make_pair(first, second));
        }
        
        
    }
    
    
    for (int i = 0; i < absolute.size(); i++)
    {
        cout << absolute[i].first << " " << absolute[i].second << " ";
    }
    


    return 0;
}