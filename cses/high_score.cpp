#include <bits/stdc++.h>
using namespace std;

void dfs(int v, int par, vector<bool>&vis, vector<vector<int>>&g) {
    vis[v] = true;
    for(auto child: g[v]) {
        if(child == par) continue;
        if(!vis[child]) 
            dfs(child, v, vis, g);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    vector<vector<int>> g(n+1);
    for(int i=1;i<=m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,-1*c});
        g[a].push_back(b);
    }
    vector<long long> dis(n+1, LONG_LONG_MAX);
    dis[1] = 0;

    bool reachable = false;
    vector<int> cycle;
    for(int i=1;i<=n;i++) {
        for(auto e: edges) {
            int u = e[0];
            int v = e[1];
            int c = e[2];
            if(dis[u] != LONG_LONG_MAX) {
                if(dis[u]+c<dis[v]) {
                    dis[v] = dis[u] + c;
                    if(i==n) 
                        cycle.push_back(v);
                }
            } 
        }
    }

    if(!cycle.empty()) {
        for(auto v: cycle) {
            vector<bool> vis(n+1, false);
            dfs(v, -1, vis, g);
            if(vis[n]) {
                reachable = true;
                break;
            }
        }
    }
    if(!cycle.empty() && reachable) 
        cout<<-1<<endl;
    else
        cout<<-1*dis[n]<<endl;
}