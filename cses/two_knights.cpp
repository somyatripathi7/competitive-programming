
#include <bits/stdc++.h>
using namespace std;

long long choose(long long n) {
    if(n<2) return 0;
    return (n*1LL*(n-1))/2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n;
    cin >> n;

    cout << 0 << endl;
    for (long long i = 2 ; i <= n ; i++) {
      cout << (i * i) * (i * i - 1) / 2 - (4 * (i - 2) * (i - 1)) << endl;
    }

    return 0;
}