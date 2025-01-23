#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int help(int n) {
	int curr = 0;
	while(n) {
		curr ++; n /= 3;
	}
	return curr;
}

int main () {
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--) {
		int l, r; cin>>l>>r;
		long long sum = 0;	
		for(int i=l; i<=r; i++) {
			sum += help(i);
		}

		long long ans =  sum + help(l);
		cout<<ans<<endl;
	}
}
