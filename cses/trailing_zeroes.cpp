#include <bits/stdc++.h>
using namespace std;

long long power(long long n, long long p) {
    long long ans = 0;
    long long div = p;
    while(n>=p) {
        ans += n/p;
        p*=div;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n;
    cin>>n;
    cout<<min(power(n, 2), power(n,5))<<endl;
}