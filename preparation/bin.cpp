#include <iostream>
#include <vector>
using namespace std;
int main() {

    vector<int> arr= {1, 2, 3, 3, 3, 3, 5};

    int target = 3;

    int left = 0, right = arr.size()-1, index = -1;

    while (left <= right)
    {
        int mid = left + (right-left)/2;
        if (arr[mid] >= target)
        {
            index = mid;
            right = mid-1;
        }
        else
        {
            left = mid +1;
        }
    }
    cout << index;
    


    return 0;
}