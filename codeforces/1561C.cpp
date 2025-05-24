#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	int n; cin>>n;
    	int mi = INT_MAX;
    	for(int j=1;j<=n;j++) {
    		int len; cin>>len;
    		int curr_mi = INT_MAX;
    		for(int k=1; k<=len; k++) {
    			int a; cin>>a;
    			curr_mi = min(curr_mi, a);
    		}
    		mi = min(mi, curr_mi);	
    	} 

    	ll ans = -1 * mi + 1;
    	cout<<ans<<endl;

    }

}
