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
    	for(int i=0;i<n;i++) cin>>v[i];

    	bool ans = true;
    	for(int i=0;i<n-1;i++) {
    		int x = min(v[i], v[i+1]);
    		v[i] = v[i] - x;
    		v[i+1] = v[i+1] - x; 
    	}

    	for(int i=1;i<n;i++) {
    		if(v[i] < v[i-1])
    			ans = false;
    	}	

    	// for(auto it: v) cout<<it<<" ";
    	// cout<<endl;

    	if(ans) cout<<"YES"<<endl;
    	else cout<<"NO"<<endl;

    }
}
