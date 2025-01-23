#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int ans = 0;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++)
            cin>>v[i];

        int curr = 1;
        for(int i=1;i<=n;i++) {
            curr = max(curr, v[i]);
            if(curr == i)
                ans++;
        }
        cout<<ans<<endl;
    }

}