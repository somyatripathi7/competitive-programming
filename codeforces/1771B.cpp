#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        int n, e; cin>>n>>e;
        map<int, int> m;
        for(int i=1;i<=e;i++) {
            int u, v; cin>>u>>v;
            if(u>v) swap(u, v);
            if(m.find(u) == m.end())
                m[u] = v;
        }

        int prev = 0;
        long long ans = (n*1LL*(n+1))/2;
        long long not_good = 0;
        for(int i=1;i<=n;i++) {
            if(m.find(i) == m.end()) continue;
            not_good += (i - prev) * 1LL * (n-m[i]+1);
            prev = i;
        }

        ans -= not_good; 
        cout<<ans<<endl;
    }
}