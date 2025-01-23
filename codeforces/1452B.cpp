#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        long long ma = 0;
        long long s = 0;
        for(int i=1;i<=n;i++) {
            long long a;
            cin>>a;
            ma = max(ma, a);
            s += a;
        }
        long long rem = s % (n-1);
        long long q = s/(n-1) + (rem!=0);
        if(ma > q) {
            q = ma; 
        }
        long long ans = q*1LL*(n-1) - s;
        cout<<ans<<endl;
    }
}