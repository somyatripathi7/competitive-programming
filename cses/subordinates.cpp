#include <bits/stdc++.h>
using namespace std;
 
int dfs(int v, vector<bool>& vis, vector<int>& ans, vector<vector<int>>& g) {
    vis[v] = true;
    int count = 0;
    for(auto child : g[v]) {
        if(vis[child]) continue;
        count += dfs(child, vis, ans, g) + 1;
    }
    ans[v] = count;
    return count;
}
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> g(n+1);
    int node = 2;
    for(int i=2;i<=n;i++) {
        int boss;
        cin >> boss;
        g[boss].push_back(node);
        node ++;
    }
    vector<int> ans(n+1, 0);
    vector<bool> vis(n+1, false);
    dfs(1, vis, ans, g);
    for(int i=1;i<=n;i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
