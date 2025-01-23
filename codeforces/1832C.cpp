#include<bits/stdc++.h>
using namespace std;
#define ll long long 	

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	int n; cin>>n;
    	vector<int> v(n);
    	for(int i=0;i<n;i++) {
    		cin>>v[i];
    	}

    	int ans = 1;
    	bool dec = false;
    	bool inc = false;
    	for(int i=1;i<v.size();i++) {
    		if(v[i] > v[i-1]) {
    			if(dec) {
    				ans ++;
    				dec = false;
    				inc = true;
    			}
    			else {
    				inc = true;
    			}
    		}
    		else if(v[i] < v[i-1]) {
    			if(inc) {
    				ans ++;
    				inc = false;
    				dec = true;
    			}
    			else
    				dec = true;
    		}
    	}

    	if(dec || inc) 
    		ans++;

    	cout<<ans<<endl;

    }
}
