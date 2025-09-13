#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    queue<int> index_s;
    queue<int> index_k;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'S')
        {
            index_s.push(i);
        }
        if (s[i] == 'K')
        {
            index_k.push(i);
        }
    }
    
    while (!index_s.empty() && !index_k.empty())
    {
        int small_is = index_s.front(); index_s.pop();
        int small_ik = index_k.front(); index_k.pop();

        if(small_is < small_ik) index_s.push(small_is + n);
        else index_k.push(small_ik + n);
    }


    if (!index_s.empty())
    {
        cout << "SAKAYANAGI";
    }
    else
    {
        cout << "KATSURAGI";
    }
    
    

    return 0;
}