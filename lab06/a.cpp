#include <iostream>
#include <vector>
using namespace std;

vector<char> arr;
vector<char> vower;
vector<char> consonant;

vector<char> v = {'a', 'e', 'i', 'o', 'u'};
vector<char> c = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};


void quicksort(int l, int r, vector<char> &arr) {
    int p = arr[(l+r)/2];
    int i = l;
    int j = r;


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
        quicksort(l, j, arr);
    }

    if (i < r)
    {
        quicksort(i, r, arr);
    }
        
}

int main() {

    int num; string s; cin >> num >> s;

    for (int i = 0; i < s.size(); i++)
    {
        arr.push_back(s[i]);
    }



    for (int i = 0; i < arr.size(); i++)
    {

        for (int j = 0; j < v.size(); j++)
        {
            if (v[j] == arr[i])
            {
                vower.push_back(v[j]);
            }        
        }

        for (int j = 0; j < c.size(); j++)
        {
            if (c[j] == arr[i])
            {
                consonant.push_back(c[j]);
            }        
        } 
    }

    if (vower.size() > 0)
    {
        quicksort(0, vower.size()-1, vower);
    }

    if(consonant.size() > 0) {
        quicksort(0, consonant.size()-1, consonant);
    }
    
    // quicksort(0, vower.size()-1, vower);
    // quicksort(0, consonant.size()-1, consonant);

    

    for (int i = 0; i < vower.size(); i++)
    {
        cout << vower[i];
    }


    for (int i = 0; i < consonant.size(); i++)
    {
        cout << consonant[i];
    }

    
    
    return 0;
}