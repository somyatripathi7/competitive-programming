#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        int n;
        cin>>n;
        long long mi = 0;
        long long ma = 0;
        long long prev_ma = 0;
        for(int i=1;i<=n;i++) {
            int a;
            cin>>a;
            ma = max({ma + a, mi + a, abs(ma + a), abs(mi + a)});
            mi = min({prev_ma + a, mi + a, abs(prev_ma + a), abs(mi + a)});
            prev_ma = ma;
        }
        cout<<ma<<endl;
    }
}