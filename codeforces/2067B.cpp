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
    	map<int, int> m;
    	for(int i = 0; i < n; i++) {
    		cin>>v[i];
    		m[v[i]]++;
    	}
    	for(auto it: m) {
    		if(it.second % 2 == 0) continue;
    		
    	}	
    }
}
