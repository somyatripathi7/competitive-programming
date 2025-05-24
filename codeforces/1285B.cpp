#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	// there is only one max subarray sum = sum of all elements
    	int n; cin>>n;
    	vector<int> v(n);
    	ll s = 0;
    	for(int i=0;i<n;i++) {
    		cin>>v[i];
    		s += v[i];
    	}

    	ll curr = 0;
    	ll ma = LONG_LONG_MIN;
    	ll mi = LONG_LONG_MAX;
    	map<int, int> m;

    	bool poss = true;
    	for(int i=0; i<n; i++) {
    		curr += v[i];
    		m[curr] ++;
    		if(curr > ma)
    			ma = curr;
    		if(curr < mi)
    			mi = curr;
    		if((curr - mi) > ma)
    			ma = curr - mi;
    		if(m.find(curr - s) != m.end()) {
    			poss = false;
    		}
    		if(i != n-1 && curr == s)
    			poss = false;
    	}	

    	if(s == ma && poss)
    		cout<<"YES"<<endl;
    	else
    		cout<<"NO"<<endl;

    }

}
