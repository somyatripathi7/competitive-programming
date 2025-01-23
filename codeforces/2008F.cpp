#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int MOD = 1e9+7;

int binpow(int a, int p) {
    int ans = 1;
    while (p > 0) {
        if (p % 2 == 1) {
            ans = (ans * 1LL * a) % MOD;
        }
        a = (a * 1LL * a) % MOD;
        p = p / 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> v(n);
        int sum = 0;
        for(int i=0;i<n;i++) {
            cin>>v[i];
            sum = (sum + v[i]) % MOD;
            if(sum < 0) sum += MOD;  // Handle negative modulo
        }
        int num = 0;
        for(int i=0;i<n;i++) {
            sum = (sum - v[i]) % MOD;
            if(sum < 0) sum += MOD;  // Handle negative modulo
            num = (num + (sum * 1LL * v[i]) % MOD) % MOD;
        }
        ll temp = (n * 1LL * (n-1))/2;
        int den = temp % MOD;
        den = binpow(den, MOD - 2);
        int ans = (num * 1LL * den) % MOD;
        cout<<ans<<endl;
    }
    return 0;
}