#include<bits/stdc++.h>
using namespace std;
#define ll long long 

bool check(vector<ll> v, ll k, ll x) {
	int n = v.size();
	for(int i = 0; i < n; i++) {
		if(v[i] < x) {
			k -= x - v[i];
			if(k < 0) return false;
		}
	}
	return true;
}

ll help(vector<ll> v) {
	int n = v.size();
	if(n == 1) return v[0];
	ll ans = v[0] * n - n + 1;
	if(v[1] > v[0]) ans += n - 1;
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--) {
    	int n, k; cin>>n>>k;
    	vector<ll> v(n);
    	for(int i = 0; i < n; i++) cin>>v[i];

    	sort(v.begin(), v.end());
    	ll low = v[0], high = v[0] + k;

    	ll change = 0;
    	while(low <= high) {
    		ll mid = (low + high)/2;
    		if(check(v, k, mid)) {
    			change = mid;
    			low = mid + 1;
    		}
    		else
    			high = mid - 1;
    	} 

    	for(int i = 0; i < n ; i++)
    		v[i] = max(v[i], change);

    	sort(v.begin(), v.end());
    	for(auto it: v) cout<<it<<" ";
    	cout<<"ans "<<help(v)<<endl;
    }
}
