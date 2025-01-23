#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	/*
    	AND > XOR if MSB is diff
    	AND == XOR if two numbers are 0 
    	*/
    	map<int, int> msb;
    	int n; cin>>n;
    	vector<int> v(n);
    	for(int i=0;i<n;i++) {
    		cin>>v[i];
    		msb[(int)log2(v[i])]++;
    	}
    	ll ans = 0;
    	for(auto it: msb) {
    		ans += (it.second * 1LL * (it.second - 1))/2;
    	}

    	cout<<ans<<endl;

    }
}
