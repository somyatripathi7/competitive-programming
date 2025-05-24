#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main () {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n; cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];

        ll s = 0, ans = 0;
        int k = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] > 0) {
                cout<<"adding s = "<<s<<" with k = "<<k<<endl;
                ans += s * 1LL * k;
                k++;
                s = 0;
                cout<<"adding s = "<<v[i]<<" with k = "<<k<<endl;
                ans += v[i] * 1LL * k;
                k++;
            }
            else {
                s += v[i];
            }
        }
        cout<<"adding s = "<<s<<" with k = "<<k<<endl;
        ans += s * 1LL * k;
    	cout<<ans<<endl;
	}
}