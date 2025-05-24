#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	int t = 1; 
    while(t--) {
    	int n; cin>>n;
    	vector<int> v;
    	for(int i=0;i<n;i++) {
    		int a; cin>>a;
    		v.push_back(a);
    	}
    	map<int, ll> m;
    	for(int i = 0; i<n; i++) {
    		//cout<<" val is "<<(v[i]-i)<<" index is "<<i<<endl;
    		m[v[i] - i] += v[i];
    	} 

    	ll ans = 0;
    	for(auto it: m) {
    		ans = max(ans, it.second);
    	}

    	cout<<ans<<endl;

    }
}
