#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	int n; cin>>n;
    	vector<pair<int, int>> v;
    	for(int i=1; i<=n; i++) {
    		int a, b; cin>>a>>b;
    		v.push_back({a, -1});
    		v.push_back({b, 1});
    	}

    	sort(v.begin(), v.end());

		for(auto it: v) {
			cout<<" time is "<<it.first<<" type is "<<it.second<<endl;
		}

    	ll ans = 0;
    	int curr = 0;
    	for(int i=0; i<v.size() ; i++) {
    		int time = v[i].first;
    		int type = v[i].second;
    		if(type == -1) //start
    			curr++;
    		else {       //end
    			curr --;
    			ans += curr;
    		}
    	}

    	cout<<" answer is "<<ans<<endl;	
    }
}
