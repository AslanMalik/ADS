#include <iostream>
#include <vector>
using namespace std;


bool primenumber(int n) {
    if (n <= 1)
    {
        return false;
    }


    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}




int main() {
    vector<int> primes;
    primes.push_back(2);
    int n, number = 3;
    cin >> n;

    while (primes.size() < n)
    {
        if (primenumber(number))
        {
            primes.push_back(number);
        }
        number++;
    }
    

    cout << primes[n-1];


    return 0;
}