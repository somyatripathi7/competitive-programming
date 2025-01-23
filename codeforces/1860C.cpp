#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main () {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n; cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
		int ans = 0;
		int lucky = 0;
		int mi = v[0];
		for(int i=1;i<n;i++) {
			mi = min(mi, v[i]);
			if(!lucky) {
				if(v[i] > v[i-1]) {
					lucky = v[i];
					ans ++;
				}
			}
			else {
				if(v[i] < lucky && v[i] > mi) {
					ans++;
				}
			}
			
		}

		cout<<ans<<endl;
    }
}
