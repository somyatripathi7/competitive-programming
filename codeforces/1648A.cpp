#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const int MOD = 1e9+7;

long long help(vector<pair<int, int>> v) {
	int n = v.size();
	vector<int> x;
	vector<int> y;
	for(auto it: v) {
		x.push_back(it.first);
		y.push_back(it.second);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	long long ans = 0;
	long long s = 0;
	for(int i=n-1; i>=0; i--) {
		s += x[i];
		ans += s - (n-i)*1LL*x[i];
	}

	s = 0;

	for(int i=n-1; i>=0; i--) {
		s += y[i];
		ans += s - (n-i)*1LL*y[i];
	}
	return ans;
}

int main () {
	ios_base::sync_with_stdio(false);
	int t = 1;
	while(t--) {
		int n, m; cin>>n>>m;
		vector<vector<int>> g(n+1, vector<int> (m+1, 0));
		map<int, vector<pair<int,int>>> color;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				int a; cin>>a;
				color[a].push_back({i, j});
			}
		}

		long long ans = 0;
		for(auto it: color) {
				ans += help(it.second);
		}	

		cout<<ans<<endl;
	}
}
