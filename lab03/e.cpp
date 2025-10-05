#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> fence;

    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int max_value = 0;
        max_value = max(max_value, x1);
        max_value = max(max_value, y1);
        max_value = max(max_value, x2);
        max_value = max(max_value, y2);
        fence.push_back(max_value);
    }

    sort(fence.begin(), fence.end());


    for (int i = 0; i < fence.size(); i++)
    {
        cout << fence[i] << " ";
    }
    
    
    return 0;
}