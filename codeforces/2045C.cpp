#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string s, t; cin>>s>>t;
    int n = s.size(); int m = t.size();
    vector<int> v(26,-1);
    for(int i=0;i<m-1;i++) v[t[i]-'a'] = i;

    int mi = INT_MAX;
    int idx = -1;
    for(int i=1;i<n;i++) {
        char ch = s[i];
        if(v[ch - 'a'] == -1) continue;
        if(m-1-v[ch-'a']+i < mi) {
            mi = m-1-v[ch - 'a']+i;
            idx = i;
        }
    }
    string ans = "-1";
    if(idx != -1) 
        ans = s.substr(0, idx).append(t.substr(v[s[idx]-'a']));
    cout<<ans<<endl;
}