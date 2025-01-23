#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
int timer = 0;

void dfs(int v, int p, vector<bool>&vis, vector<int>&tin, vector<int>&low, vector<vector<int>>&g) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    for(auto child : g[v]) {
        if(child == p) continue;
        if(!vis[child]) {
            dfs(child, v, vis, tin, low, g);
            low[v] = min(low[v], low[child]);
        }
        else 
            low[v] = min(low[v], tin[child]);
        if(low[child]>tin[v]) 
            ans.push_back({v, child});
    } 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    for(int i=1;i<=m;i++) {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool> vis(n+1, false);
    vector<int> tin(n+1, INT_MAX);
    vector<int> low(n+1, INT_MAX);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            dfs(i, -1, vis, tin, low, g);
        }
    }
    
    for(auto it: ans) {
        cout<<it[0]<<" "<<it[1];
    }

}