#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


bool cmp(string s1, string s2) {
    if (s1.size() != s2.size()) return s1.size() < s2.size();
    return true;
    
}


void merge(vector<string> &arr, int left, int mid, int right) {
    int n1 = mid-left+1, n2 = right-mid;

    vector<string> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[(mid+1)+i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (cmp(L[i],R[j]))
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
        arr[k] = L[i]; i++; k++;
    }

    while (j < n2)
    {
        arr[k] = R[j]; j++; k++;
    }
    

}


void mergersort(vector<string> &arr, int left, int right) {
    if (left < right)
    {
        int mid = left + (right-left)/2;

        mergersort(arr, left, mid);
        mergersort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
    
}



void print(vector<string> &arr) {
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}


int main() {
    
    int n; cin >> n; cin.ignore();

    for (int i = 0; i < n; i++)
    {
        vector<string> arr; 
        string line;

        getline(cin, line);

        stringstream ss(line);
        string word;
        
        while (ss >> word) {
            arr.push_back(word);
        }

        mergersort(arr, 0, arr.size()-1);
        print(arr);
    }
    
    

    return 0;
}