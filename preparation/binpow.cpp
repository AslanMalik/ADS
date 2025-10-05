#include <iostream>
using namespace std;


int binpow(int a, int n) {
    if (n == 0)
    {
        return 1;
    }

    if (n % 2 == 0)
    {
        int half = binpow(a, n/2);
        return half * half;
    }
    else
    {
        return a * binpow(a, n-1);
    }
    
    
    
}

int pinpow_iter(int a, int n) {
    int result = 1;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            result *= a;
        }

        a *= a;
        n /= 2;
    }
    return result;

}

int main() {
    int a, n; cin >> a >> n;

    cout << pinpow_iter(a, n);
    return 0;
}