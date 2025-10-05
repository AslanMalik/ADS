<<<<<<< HEAD
#include <iostream>
#include <vector>
using namespace std;
int main() {

    int n, m, sum_all = 0;
    cin >> n >> m;
    vector<int> pref;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        sum_all+= k;
        pref.push_back(sum_all);
    }




    for (int i = 0; i < m; i++)
    {
        int mistake;
        cin >> mistake;

        int left = 0, right = n-1, answer = -1;

        while (left <= right)
        {
            int mid = left + (right-left)/2;
            if (pref[mid] >= mistake)
            {
                right = mid - 1;
                answer = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        cout << answer + 1 << endl;
    }
    
    

    return 0;
=======
#include <iostream>
#include <vector>
using namespace std;
int main() {

    int n, m, sum_all = 0;
    cin >> n >> m;
    vector<int> pref;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        sum_all+= k;
        pref.push_back(sum_all);
    }




    for (int i = 0; i < m; i++)
    {
        int mistake;
        cin >> mistake;

        int left = 0, right = n-1, answer = -1;

        while (left <= right)
        {
            int mid = left + (right-left)/2;
            if (pref[mid] >= mistake)
            {
                right = mid - 1;
                answer = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        cout << answer + 1 << endl;
    }
    
    

    return 0;
>>>>>>> de48af3842509f5816df4fa4c2e9b90f20513536
}