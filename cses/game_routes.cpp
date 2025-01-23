#include <bits/stdc++.h>
using namespace std;

void dfs(int v, int n, vector<vector<int>>&g, int& ways) {
    if(v==n) {
        ways++;
        return;
    }
    for(auto child: g[v]) {
        dfs(child, n, g, ways);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    int ans = 0;
    dfs(1, n, g, ans);
    cout<<ans;
}