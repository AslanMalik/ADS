#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector<int> arr;

    int n;
    cin >> n;



    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        arr.push_back(k);
    }

    vector<int> power(n+1);
    power[0] = 0;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        power[i+1] = power[i] + arr[i]; 
    }



    


    int p;
    cin >> p;

    for (int i = 0; i < p; i++)
    {
        int mark;
        cin >> mark;


        int left = 0, right = arr.size()-1;

        while (left <= right)
        {
            int mid = left + (right-left)/2;

            if (mark >= arr[mid])
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            } 
        }

        int score = left;

        cout << score << " " << power[score] << endl;
        
    }
    
    
    return 0;
}