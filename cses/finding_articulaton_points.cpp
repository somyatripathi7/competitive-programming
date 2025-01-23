
#include <bits/stdc++.h>
using namespace std;

set<int> points;
int timer = 0;

void dfs(int v, int p, vector<bool>&vis, vector<int>&tin, vector<int>&low, vector<vector<int>>&g) {
    low[v] = tin[v] = timer++;
    vis[v] = true;
    int children = 0;
    for(auto child: g[v]) {
        if(child == p) continue;
        if(vis[child]) 
            low[v] = min(low[v], tin[child]);
        else {
            children++;
            dfs(child, v, vis, tin, low, g);
            low[v] = min(low[v], low[child]);
            if(low[child] >= tin[v] && p!=-1)
                points.insert(v);
        }
    }
    if(p == -1 && children>1) {
        points.insert(v);
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

    vector<int> tin(n+1, INT_MAX);
    vector<int> low(n+1, INT_MAX);
    vector<bool> vis(n+1, false);
    for(int i=1;i<=n;i++) {
        if(!vis[i])
            dfs(i, -1, vis, tin, low, g);
    }
    for(auto it: points) {
        cout<<it<<" ";
    } 
}