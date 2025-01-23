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
		
		long long sum = 0;
		for(int i=1;i<n;i++) {
			int d = v[i] - v[i-1];
			sum += d;
			sum -= d * 1LL * (n-i) * 1LL * (i);	
		}	
			cout<<sum<<endl;
	}
}
