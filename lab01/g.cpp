#include <iostream>
#include <vector>
using namespace std;


bool prime_number(int number) {

    if (number <= 1)
    {
        return false;
    }
    


    for (int i = 2; i*i <= number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}






int main() {
    int n;
    cin >> n;

    vector<int> primes;
    vector<int> primes_index;

    for (int i = 2; i < 4001; i++)
    {
        if (prime_number(i))
        {
            primes.push_back(i);
        }
        
    }
    

    for (int i = 0; i < primes.size(); i++)
    {
        if (prime_number(i+1))
        {
            primes_index.push_back(primes[i]);
        }
        
    }
    


   cout << primes_index[n-1];
    


    return 0;
}