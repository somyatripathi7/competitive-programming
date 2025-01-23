#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 4e5 + 10;
vector<int> par(N, 0);
vector<int> siz(N, 0);

void make(int a) {
	par[a] = a;
	siz[a] = 1;
}

int find(int a) {
	if(par[a] == a) return a;
	return par[a] = find(par[a]);
}

void Union(int a, int b) {
	a = find(a); b = find(b);
	if(a==b) return;
	if(siz[a] < siz[b]) swap(a, b);
	siz[a] += b;
	par[b] = a;
}

int main() {
	//keep the common edges
	/* 
	complete the entire graph G
	complete only common for F
	for the extra ones present in F, check if we need to add it in G
	for the 
	*/
	//F me 1, G me 2
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	int n, x, y; cin>>n>>x>>y;
    	fill(par.begin(), par.begin() + 2*n + 10, 0);
    	fill(siz.begin(), siz.begin() + 2*n + 10, 0);
    	map<vector<int>, int> e;
    	for(int i=1;i<=n;i++) {
    		make(i); make(i+n);
    	}
    	for(int i=1;i<=x;i++) {
    		int u, v; cin>>u>>v;
    		if(u > v) swap(u, v);
    		e[{u, v}] ++;
    	}

    	for(int i=1;i<=y;i++) {
    		int u, v; cin>>u>>v;
    		if(u > v) swap(u, v);
    		e[{u, v}] += 2;
    		Union(u+n, v+n);
    	}

    	for(auto it: e) {
    		vector<int> edges = it.first;
    		if(it.second == 3) 
    			Union(edges[0], edges[1]);
    	}

    	int ans = 0;
    	for(auto it: e) {
    		vector<int> edges = it.first;
    		int u = edges[0]; int v = edges[1];
    		if(it.second == 1) { 
    		//present only in F
    		// if vertices are NOT connected in G then remove it, otherwise build F 
    			if(find(u+n) != find(v+n)) ans ++;
    			else Union(u, v);
    		}
    		else if(it.second == 2) {
    			//present only in G
    			//if vertices are NOT connected in F then add the edge
    			if(find(u) != find(v)) {
    				ans ++;
    				Union(u, v);
    			}

    		}
    	}
    	cout<<ans<<endl;
    }
}
