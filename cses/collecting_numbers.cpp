#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    unordered_map<int,int> m;
    for(int i=1;i<=n;i++) {
        int a;
        cin>>a;
        m[a] = i;
    }
    vector<int> v(n+1, 0);
    for(int i=1;i<=n;i++) {
        v[i] = m[i];
    }
    int ans = 0;
    for(int i=2;i<=n;i++) {
        if(v[i]>v[i-1]) continue;
        ans ++;
    }
    ans++;
    cout<<ans<<endl;
}