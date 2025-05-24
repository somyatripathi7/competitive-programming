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
    	for(int i=0; i<n; i++) cin>>v[i];

    	bool dec = false;
    	bool inc = false;

    	vector<int> ans;
    	ans.push_back(v[0]);

    	for(int i=1; i<n; i++) {
    		if(v[i] > v[i-1]) {
    			inc = true;
    			if(dec) {
    				ans.push_back(v[i-1]);
    				dec = false;
    			}
    		}
    		else if(v[i] < v[i-1]) {
    			dec = true;
    			if(inc) {
    				ans.push_back(v[i-1]);
    				inc = false;
    			}
    		}
    	}

    	ans.push_back(v[n-1]);
    	cout<<ans.size()<<endl;
    	for(auto it: ans) cout<<it<<" ";
    	cout<<endl;

    }
}
