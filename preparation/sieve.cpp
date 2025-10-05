#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve(int n) {
    vector<bool> is_prime(n+1, true);
    
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        for (int j = i * i; j <= n; j+=i)
        {
            is_prime[j] = false;
        }
    }

    vector<int> prime;

    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
        }
    }

    return prime;
    
    
}


int main() {
    int n; cin >> n;

    vector<int> number = sieve(n);

    for (int i = 0; i < number.size(); i++)
    {
        cout << number[i] << " ";
    }
    
    return 0;
}