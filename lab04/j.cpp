#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


void build(int l, int r, vector<int> &arr) {

    if(l > r) return;

    int m = l + (r-l)/2;
    cout << arr[m] << " ";
    build(l, m-1, arr);
    build(m+1, r, arr);

}


int main() {

    int n; cin >> n;
    int number = pow(2, n);
    vector<int> arr;


    for (int i = 0; i < number-1; i++)
    {
        int k; cin >> k;
        arr.push_back(k);
    }

    sort(arr.begin(), arr.end());



    build(0, number-2, arr);




    return 0;
}