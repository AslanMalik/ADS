#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        deque<int> index;
        vector<int> answer(n);
        for (int k = 0; k < n; k++)
        {
            index.push_back(k+1);
        }

        for (int k = 1; k < n+1; k++)
        {
            for (int j = 0; j < k; j++)
            {
                int front = index.front();
                index.pop_front();
                index.push_back(front);                
            }
            answer[index.front()-1] = k;
            index.pop_front();
        }


        for (int k = 0; k < answer.size(); k++)
        {
            cout << answer[k] << " ";
        }
        
        cout << endl;
        
        
    }
    
    






    return 0;
}