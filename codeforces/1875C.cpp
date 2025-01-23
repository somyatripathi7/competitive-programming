#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main () {
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--) {
		int n, k; cin>>n>>k;
		vector<int> f(n);
		vector<int> h(n);
		for(int i=0;i<n;i++) cin>>f[i];
		for(int i=0;i<n;i++) cin>>h[i];

		int l = 0, r = 0;
		long long sum = 0;
		int ans = 0;
		for(r = 0; r<n; r++) {
			if( r == 0 || h[r-1]%h[r] == 0) {
				sum += f[r];
			}
			else {
				sum = f[r];
				l = r;
			} 
			while(l<n && sum > k) {
				sum -= f[l];
				l++;
			}
			if(r-l + 1 > ans) {
				ans = r-l+1;
			}
		}

		cout<<ans<<endl;
	}
}
