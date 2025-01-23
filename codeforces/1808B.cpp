#include<bits/stdc++.h>
using namespace std;
#define ll long long 	

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	int n, m; cin>>n>>m;
    	vector<vector<int>> v(n, vector<int> (m, 0));
    	for(int i=0;i<n;i++) {
    		for(int j=0;j<m;j++) cin>>v[i][j];
    	}

    	ll ans = 0;
    	for(int j = 0; j<m; j++) {
    		vector<int> curr;
    		ll sum = 0;
    		for(int i=0;i<n;i++) {
    			curr.push_back(v[i][j]);
    			sum += v[i][j];
    		}
    		sort(curr.begin(), curr.end());
    		for(int i=0;i<n;i++) {
    			ans += sum - (n-i) * 1LL * curr[i];
    			sum -= curr[i];
    		}
    	}
    	cout<<ans<<endl;	
    }
}
