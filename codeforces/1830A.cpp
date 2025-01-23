#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const int N = 2e5 + 1;
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
	if(siz[b]>siz[a]) swap(a, b);

	par[b] = a;
	siz[a] += siz[b];
}


int main () {
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		for(int i=1;i<=n;i++) {
			par[i] = -1;
			siz[i] = 0;
		}
		int ans = 1;
		int curr = 0;
		for(int i=1;i<=n-1;i++) {
			int a, b; cin>>a>>b;
			if(par[a] == -1 && par[b] == -1) {
				make(a); make(b);
				Union(a, b);
				curr++; 
			}
			else if(par[b] == -1) {
				make(b);
				Union(a, b);
			}
			else if(par[a] == -1) {
				make(a);
				Union(a, b);
			}
			else {
				if(find(a) != find(b))
					curr--;
				Union(a, b);
			}
			ans = max(ans, curr);
		}
		cout<<ans<<endl;	
	}
}
