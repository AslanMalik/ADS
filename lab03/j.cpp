#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    int n, h;
    cin >> n >> h;

    vector<float> bag;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        bag.push_back(k);
    }

    sort(bag.begin(), bag.end());

    float max_value = bag[bag.size()-1];
    
    int left = 1, right = max_value;

    while (left <= right)
    {
        float all_hours = 0;
        int mid = left + (right-left)/2;

        for (int i = 0; i < n; i++)
        {
            all_hours += ceil(bag[i]/mid);
        }

        if (all_hours > h)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << left;
    
    return 0;
}