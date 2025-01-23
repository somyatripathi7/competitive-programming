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

    	int prev1 = v[0], prev2 = -1;
    	int ans = 0;

    	//prev1 > prev2

    	for(int i=1;i<n;i++) {
    		if(prev2 == -1) {
    			if(v[i] <= prev1)
    				prev1 = v[i];
    			else 
    				prev2 = v[i]; 
    		}
    		else {
    			if(v[i] <= prev1 && v[i] <= prev2) {
    				if(prev1 <= prev2) 
    					prev1 = v[i];
    				else
    					prev2 = v[i];
    			}
    			else if(v[i] > prev1 && v[i] <= prev2)
    				prev2 = v[i];
    			else if(v[i] > prev2 && v[i] <= prev1)
    				prev1 = v[i];
    			else {
    				ans ++;
    				if(prev1 <= prev2) 
    					prev1 = v[i];
    				else
    					prev2 = v[i];
    			}
    		}
    	}

    	cout<<ans<<endl;

    }
}
