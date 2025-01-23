#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const int N = 1e6 + 5;
vector<int> factor(N, 1); 

void findPrimes() {
	for(int i=2;i<N;i++) {
		if(factor[i] == 1) {
			factor[i] = i;
			for(int j=i*2; j<N; j+=i) {
				if(factor[j] == 1) factor[j] = i; 
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    findPrimes();
    while(t--) {
    	int n; cin>>n;
    	ll ans = 0;
    	string s; cin>>s;
    	bool one = false;
    	if(s[0] == '1') one = true;
    	for(int i=1;i<=n;i++) {
    		if(s[i-1] == '0') {
    			if (one) {
    				ans += 1;
    				cout<<"factor of "<<i<<" is "<<1<<endl;
    			}
    			else {
    				cout<<"factor of "<<i<<" is "<<factor[i]<<endl;
    				ans += factor[i];
    			}
    		}
    	}

    	cout<<"final "<<ans<<" "<<endl;

    }
}
