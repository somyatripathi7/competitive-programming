#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        map<int, int> m;
        for(int i=1;i<=n;i++) {
            int a; cin>>a;
            m[a]++;
        }
        priority_queue<int> q;
        for(auto it: m) q.push(it.second);

        int curr = INT_MAX;
        long long ans = 0;
        while(!q.empty() && curr>0) {
            curr = min(curr, q.top()); q.pop();
            ans += curr;
            curr --;
        }
        
        cout<<ans<<endl;
    }
}