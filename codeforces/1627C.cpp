#include <bits/stdc++.h>
using namespace std;

void dfs(int v, int p, int c, vector<bool>& vis, vector<vector<int>>& g, map<vector<int>, int>& e, vector<int>& ans) {
    vis[v] = true;
    if(p != -1) {
        if(p>v)
            ans[e[{v, p}]] = c;
        else
            ans[e[{p, v}]] = c;
    }
    int done = 0;
    for(auto child : g[v]) {
        if(vis[child]) continue;
        c = 5 - c;
        dfs(child, v, c, vis, g, e, ans);
        done ++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<vector<int>> g(n+1);
        map<vector<int> , int> e;
        vector<int> degree(n+1);
        int flag = 0;
        for(int i=0;i<n-1;i++) {
            int u, v; cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            if(u>v) swap(u, v);
            degree[u]++;
            degree[v]++;
            if(degree[u] > 2 || degree[v] > 2) {
                flag = 1;
            }
            e[{u, v}] = i;
        }
        if(flag) {
            cout<<-1<<endl;
        }
        else {
            vector<int> ans(n-1, 0);
            vector<bool> vis(n, 0);
            dfs(1, -1, 2, vis, g, e, ans);
            for(auto it: ans)
                cout<<it<<" ";
            cout<<endl;
        }
    }

}