
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> v;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }
    unordered_map<int,int> m;
    int ans = 0;
    int l = 0;
    for(int i=0;i<n;i++) {
        if(m.find(v[i]) != m.end() && m[v[i]]>=l) {
            l = m[v[i]]+1;
        }
        m[v[i]] = i;
        ans = max(ans, i-l+1);
    }
    cout<<ans<<endl;
}
