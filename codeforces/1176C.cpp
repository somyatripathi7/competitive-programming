#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int N = 5e5 + 10;
vector<int> par(N, 0);
vector<int> siz(N, 0);

void make(int a) {
	par[a] = a;
	siz[a] = 1;
}

int find(int a) {
	if(a == par[a]) return a;
	return par[a] = find(par[a]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return;
	if(siz[a] < siz[b]) swap(a, b);
	par[b] = a;
	siz[a] += siz[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--) {
    	int n, m; cin>>n>>m;
    	for(int i=1;i<=n;i++) make(i);
    	for(int i=1;i<=m;i++) {
    		int k; cin>>k;
    		int prev = -1; 
    		for(int j=1;j<=k;j++) {
    			int a; cin>>a;
    			if(prev != -1)
    				Union(a, prev);
    			prev = a;
    		}	
    	}

    	map<int, int> groups;
    	for(int i=1;i<=n;i++) {
    		int par = find(i);
    		groups[par] ++;
    	}

    	for(int i=1;i<=n;i++) {
    		int par = find(i);
    		cout<<groups[par]<<" ";
    	}

    	cout<<endl;
    }
}
