#include <iostream>
using namespace std;
void primeFactorization(int n) {
    for(int i = 2; i*i <= n; i++)
    {
        while (n % i ==0)
        {
            cout << i << " ";
            n /= i;
        }
    }

    if (n > 1)
    {
        cout << n << " ";
    }
    
    

// 1 2 3 4 5 6 7 8 9 10 11  10
    


}
int main() {

    int n; cin >> n;
    primeFactorization(n);
    return 0;
}