#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> arr;

    int size, query;

    cin >> size >> query;

    for (int i = 0; i < size; i++)
    {
        int k;
        cin >> k;
        arr.push_back(k);
    }

    sort(arr.begin(), arr.end());
    

    for (int i = 0; i < query; i++)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r2 >> l2 >> r2;



        int left = 0, right = arr.size()-1;
        vector<int> asnwer(2) = 0;

        while (left <=right)
        {
            int mid = left + (right-left)/2;

            if (l1 <= arr[mid] && arr[mid] <= r1)
            {
                asnwer[0] = mid+1;
            }

            


            
        }
        
    }
    

    return 0;
}