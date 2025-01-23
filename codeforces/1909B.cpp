#include<bits/stdc++.h>
using namespace std;
#define ll long long 	

int help(int n) {
	int curr = 0;
	int ans = 0;
	while(n > 0) {
		if(n % 2 != 0){
			ans = curr;
			break;
		}
		curr++;
		n = n/2;
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	//answer is the 2^(min set bit + 1) min set bit
    	int n; cin>>n;
    	int odd = 0, mi = INT_MAX;
    	for(int i=0;i<n;i++) {
    		int a; cin>>a;
    		mi = min(mi, help(a));
    	}

    	long long ans = 1ll<<(mi+1);
    	cout<<ans<<endl;
    	
    	}
}
