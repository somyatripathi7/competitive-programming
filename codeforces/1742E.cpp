#include<bits/stdc++.h>
using namespace std;
#define ll long long 	

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	int n, q; cin>>n>>q;
    	vector<int> v(n);
    	vector<int> ma(n);
    	vector<ll> pre(n);
    	for(int i=0;i<n;i++) {
    		cin>>v[i];
    		if(i>0) {
    			ma[i] = max(ma[i-1], v[i]);
    			pre[i] = pre[i-1] + v[i];
    		}
    		else {
    			ma[i] = v[i];
    			pre[i] = v[i];
    		}
    	}

    	for(int i=0;i<q;i++) {
    		int x; cin>>x;
    		int idx = upper_bound(ma.begin(), ma.end(), x) - ma.begin() - 1;
    		if(idx == -1) cout<<0<<" ";
    		else {
    			ll ans = pre[idx];
    			cout<<ans<<" ";
    		}	
    	}
    	cout<<endl;





    }
}
