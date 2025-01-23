#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	int n; cin>>n;
    	vector<int> v(n+1);
    	map<int, int> pre;
    	for(int i=1;i<=n;i++) {
    		cin>>v[i];
    		pre[v[i]] = i;
    	}

    	set<pair<int, int>> s;
    	if(pre.size() > 1) {
    		cout<<"YES"<<endl;
	    	for(int i=1;i<=n-1;i++) {
	    		for(int j=1;j<=n;j++) {
	    			if(v[i] != v[j]) {
	    				int a = i, b = j;
	    				if(a > b) swap(a, b);
		    				if(s.find({a,b}) == s.end()) {
		    				cout<<i<<" "<<j<<endl;
		    				s.insert({a, b});
		    				break;
	    				}
	    			}
	    		}
	    	}
    	}
    	else 
    		cout<<"NO"<<endl;


    }
}
