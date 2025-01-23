#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        int l = 0;
        int r = 0;
        map<int, int> m;
        vector<int> v(n);

        for(int i=0;i<n;i++) cin>>v[i];
        sort(v.begin(), v.end());
        int ans = 0;

        while(r<n) {
            m[v[r]]++;
            while(m.size()>k) {
                m[v[l]]--;
                if(m[v[l]] == 0)
                    m.erase(v[l]);
                l++;
            }
            if(l<=r-1) {
                if(v[r]-v[r-1]>1) {
                    while(l<r) {
                        m[v[l]]--;
                        if(m[v[l]] == 0)
                            m.erase(v[l]);
                        l++;
                    }
                }
            }
            ans = max(ans, r-l+1);
            r++;
        }

        cout<<ans<<endl;

    }
}