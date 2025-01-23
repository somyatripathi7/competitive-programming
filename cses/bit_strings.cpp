#include <iostream>
using namespace std;

long long pow_mod(long long a, long long n, long long mod) {
    long long result = 1;
    a = a % mod; 
    while(n) {
        if(n&1) {
            result = (result * a)%mod;
        }
        a = (1LL*a*a)%mod;
        n>>=1;
    }
    return result;
}

int main() {
    long long n;
    cin>>n;
    long long mod = 1e9+7;
    cout << pow_mod(2, n, mod) << endl;    // Correct result < mod
    return 0;
}