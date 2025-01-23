#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const int MOD = 1e9+7;

int main () {
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--) {
		//each cc of size > 1 has 2 ways if not already set
		int n; cin>>n;
		vector<int> a(n);
		vector<int> b(n);
		vector<int> c(n);
		vector<bool> mark(n, false);

		map<int, vector<int>> m;
		for(int i=0;i<n;i++) cin>>a[i];	
		for(int i=0;i<n;i++) cin>>b[i];	
		for(int i=0;i<n;i++) cin>>c[i];

		for(int i=0;i<n;i++) {
			m[a[i]].push_back(i);
			if(a[i] != b[i])
				m[b[i]].push_back(i);
		}

		int ans = 1;

		for(int i=0;i<n;i++) {
			if(mark[i]) {
				continue;
			}
			int A = a[i]; int B = b[i]; 
			mark[i] = true;
			int siz = 1;
			while(A != b[i]) {
			for(int j=0;j<m[A].size();j++) {
					if(m[A][j] == i) continue;
					siz ++;
					int pos = m[A][j];
					A = a[pos];
					B = b[pos];
					c[i] = max(c[i], c[pos]);
					mark[pos] = true;
				}
			}
			if(c[i] == 0 && siz>1) ans = (ans*1LL*2)%MOD;
		}
		cout<<ans<<endl;

	}
}	

