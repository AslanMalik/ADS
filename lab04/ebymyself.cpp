#include <iostream>
#include <queue>
using namespace std;

const int N = 200000 + 5;
int L[N], R[N], dep[N], cnt[N];

int main() {
    int n; cin >> n;

    for (int i = 1; i <= n; i++)
    {
        L[i] = R[i] = 0;
    }


    for (int i = 0; i < n-1; i++)
    {
        int x, y, z; cin >> x >> y >> z;

        if (z == 0)
        {
            L[x] = y;
        }
        else
        {
            R[x] = y;
        }
    }

    queue<int> q;
    q.push(1);
    dep[1] = 1;
    int mx = 1;

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        mx = max(mx, dep[u]);
        cnt[dep[u]]++;

        if (L[u])
        {
            dep[L[u]] = 1 + dep[u]; q.push(L[u]);
        }

        if (R[u])
        {
            dep[R[u]] = 1 + dep[u]; q.push(R[u]);
        }
    }

    int max_element = 0;

    for (int i = 1; i <= mx; i++)
    {
        max_element = max(max_element, cnt[i]);
    }

    cout << max_element;


    
    
    

    return 0;
}