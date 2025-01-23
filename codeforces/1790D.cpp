#include<bits/stdc++.h>
using namespace std;
#define ll long long 	

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	//find max possible number of increasing subsequences
    	int n; cin>>n;
    	vector<int> v(n);
    	map<int, int> m;
    	for(int i=0;i<n;i++) {
    		cin>>v[i];
    	}

    	sort(v.begin(), v.end());
    	int ans = 0;

    	m[v[0]] = 1;
    	int curr_ma = 1;
    	for(int i=1;i<n;i++) {
    		if(v[i] - v[i-1] <= 1) {
    			m[v[i]] ++;
    			curr_ma = max(curr_ma, m[v[i]]);
    		}
    		else {
    			m[v[i]] ++;
    			ans += curr_ma;
    			curr_ma = 1;
    		}
    	}

    	ans += curr_ma;

    	cout<<ans<<endl;


    }
}
