#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;  
    cin>>n;
    vector<vector<int>> v;
    for(int i=1;i<=n;i++) {
        int a, b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    long long t = 0;
    for(auto it: v) {
        t += it[0];
        ans += it[1] - t;
    }
    cout<<ans<<endl;
}