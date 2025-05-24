#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--) {
    	int n; cin>>n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++) {
    		cin>>v[i];
    	}

    	map<int, vector<int>> m;
    	for(int i = 0; i <= 20; i++) {
    		for(int j = 0; j < n; j++) {
    			if(v[j] & (1<<i)) m[i].push_back(j);
    		}
    	}

    	int ans = 1;
    	for(auto it: m) {
    		vector<int> pos = it.second;
    		int prev = -1;
    		//cout<<"bits at pos "<<it.first<<" is set at ";
    		for(int i = 0; i < pos.size(); i++) {
    			//cout<<pos[i]<<" ";
    			ans = max(ans, pos[i] - prev);
    			prev = pos[i];
    		}
    		ans = max(ans, n-prev);
    	}

    	cout<<ans<<endl;
 
    }
}
