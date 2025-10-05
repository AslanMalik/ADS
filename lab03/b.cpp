<<<<<<< HEAD
#include <iostream>
#include <vector>
using namespace std;
int main() {

    long long n, k, max_number = 0, sum_all = 0;
    cin >> n >> k;
    vector<long long> arr;

    for (int i = 0; i < n; i++)
    {
        long long ai;
        cin >> ai;
        max_number = max(max_number, ai);
        sum_all += ai;
        arr.push_back(ai);
    }



    long long left = max_number, right = sum_all;

    while (left < right)
    {
        long long mid = left + (right-left)/2;

        long long total_block = 0, current_sum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (current_sum + arr[i] <= mid)
            {
                current_sum += arr[i];
            }
            else
            {
                total_block++;
                current_sum = arr[i];
            }
        }

        total_block++;

        if (total_block > k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
        
    }
    
    cout << right;
    



    return 0;
}
=======
#include <iostream>
#include <vector>
using namespace std;
int main() {

    long long n, k, max_number = 0, sum_all = 0;
    cin >> n >> k;
    vector<long long> arr;

    for (int i = 0; i < n; i++)
    {
        long long ai;
        cin >> ai;
        max_number = max(max_number, ai);
        sum_all += ai;
        arr.push_back(ai);
    }



    long long left = max_number, right = sum_all;

    while (left < right)
    {
        long long mid = left + (right-left)/2;

        long long total_block = 0, current_sum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (current_sum + arr[i] <= mid)
            {
                current_sum += arr[i];
            }
            else
            {
                total_block++;
                current_sum = arr[i];
            }
        }

        total_block++;

        if (total_block > k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
        
    }
    
    cout << right;
    



    return 0;
}
>>>>>>> de48af3842509f5816df4fa4c2e9b90f20513536
