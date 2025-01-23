
#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, int c, vector<int>& color, vector<vector<int>>& g) {
    if(color[v] != 0) {
        if(color[v] == c) 
            return true;
        return false;
    }
    color[v] = c;
    bool poss = true;
    int new_c = c==1?2:1;
    for(auto child : g[v]) {
        poss &= dfs(child, new_c, color, g);
        if(!poss) return false;
    }
    return true;
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
        g[v].push_back(u);
    }
    int flag = 0;
    vector<int> color(n+1, 0);
    for(int i=1;i<=n;i++) {
        if(color[i] == 0) {
            bool poss = dfs(i, 1, color, g);
            if(!poss) {
                cout<<"IMPOSSIBLE"<<endl;
                flag = 1;
                break;
            }
        }
    }
    if(!flag) {
        for(int i=1;i<=n;i++) {
        cout<<color[i]<<" ";
        }
    }
    cout<<endl;
}