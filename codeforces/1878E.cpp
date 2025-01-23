#include<bits/stdc++.h>
using namespace std;
#define ll long long 

bool check(vector<vector<int>>& prefix,int l, int k, int x) {
	vector<int> bits(31, 0);
	int num = 0;
	for(int i=0;i<=30;i++) {
		if(prefix[x][i] - prefix[l-1][i] == x-l+1)
			num |= 1<<i;
	}
	return num >= k;
}

int main () {
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--) {
	int n; cin>>n;
	vector<int> v(n+1);
	for(int i=1;i<=n;i++) cin>>v[i];

	vector<vector<int>> prefix(n+1, vector<int>(31, 0));
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=30;j++) {
			prefix[i][j] = prefix[i-1][j];
			if(v[i] & (1<<j)) {
				prefix[i][j]++;
			}
		}
	}

	int q; cin>>q;
	while(q-- ) {
		int l, k; cin>>l>>k;
		int low = l;
		int high = n;

		int ans = -1;
		while(low<=high) {
			int mid = (low + high)/2;
			if(check(prefix, l, k, mid)) {
				ans = mid;
				low = mid+1;
			}
			else
				high = mid-1;
		}
		cout<<ans<<" ";

		}
		cout<<endl;
	}
}