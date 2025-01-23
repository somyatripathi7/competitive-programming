#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main () {
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		vector<int> deg(n+1, 0);
		vector<vector<int>> g(n+1);
		for(int i=1;i<=n;i++) {
			string s; cin>>s;
			for(int j=1;j<=n;j++) {
				if(s[j-1] == '1') {
					if(i<j) {
						deg[j]++;
						g[i].push_back(j);
					}
					else {
						deg[i]++;
						g[j].push_back(i);
					}
				}
			}	
		}

		vector<int> ans;
		priority_queue<int> q;
		for(int i=n;i>=1;i--) if(deg[i] == 0) q.push(i);
		while(!q.empty()) {
			int v = q.top(); q.pop();
			ans.push_back(v);
			for(auto child: g[v]) {
				deg[child]--;
				if(deg[child] == 0)
					q.push(child);
			}
		}

		for(auto it: ans) cout<<it<<" ";
		cout<<endl;

	}
}
