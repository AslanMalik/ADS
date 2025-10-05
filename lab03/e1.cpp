#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> fenceX2, fenceY2;

    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        fenceX2.push_back(x2);
        fenceY2.push_back(y2);
    }


    int left = 0, right = 1000000000;
    while (left <= right)
    {
        int mid = left + (right-left)/2;

        int count = 0;

        for (int i = 0; i < fenceX2.size(); i++)
        {
            if (mid >= fenceX2[i] && mid >= fenceY2[i])
            {
                count++;
            }
        }

        if (count >= k)
        {
            right = mid -1;
        }
        else
        {
            left = mid+1;
        }
        
        
        
    }
    
    cout << right+1;
    
    return 0;
}