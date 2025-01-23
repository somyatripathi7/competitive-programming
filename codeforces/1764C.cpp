#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main () {
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++) cin>>v[i];
		sort(v.begin(), v.end());
		int ans = 0;
		for(int i=1;i<=n-2;i++) {
			int diff1 = v[i] - v[i-1];
			int diff2 = v[n-1] - v[i-1];
			ans = max(ans, diff1 + diff2);
		}

		reverse(v.begin(), v.end());


		for(int i=1;i<=n-2;i++) {
			int diff1 = abs(v[i] - v[i-1]);
			int diff2 = abs(v[n-1] - v[i-1]);
			ans = max(ans, diff1 + diff2);
		}

		cout<<ans<<endl;

	}
}
