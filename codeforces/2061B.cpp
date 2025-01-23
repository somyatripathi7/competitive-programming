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

    	sort(v.begin(), v.end());	

    	int diff = INT_MAX;
    	vector<vector<int>> pre(n, {-1, -1});
    	vector<int> sides = {-1, -1};

    	for(int i=n-2;i>=0;i--) {
    		if(v[i+1] - v[i] < diff) {
    			sides = {i, i+1};
    			pre[i] = sides;
    			diff = v[i+1] - v[i];
    		}
    	}

    	for(int i=1;i<=n-3;i++) {
    		if(v[i] != v[i-1]) continue;
    		if(abs())
    	}

    	if(!poss) cout<<-1<<endl;

    }
}
