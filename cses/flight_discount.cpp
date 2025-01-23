
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<vector<int>>> g(n+1);
    map<pair<int,int>, int> edges;
    for(int i=1;i<=m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b, c, 0});
        g[a].push_back({b, c/2, 1});
    }
    priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> q;
    vector<vector<long long>> dis(n + 1, vector<long long>(2, LONG_LONG_MAX));
    q.push({0,1,0});
    while(!q.empty()) {
        long long d = q.top()[0];
        long long v = q.top()[1];
        long long used = q.top()[2];
        q.pop();
        if(dis[v][used] <= d) continue;
        dis[v][used] = d;
        if(v == n && used) break;
        for(auto child : g[v]) {
            int child_v = child[0];
            int child_d = child[1];
            int child_used = child[2];
            if(child_used == 0) {
                if(child_d + d < dis[child_v][used]) {
                    q.push({child_d + d, child_v, used});
                }
            }
            else {
                if(!used) {
                    if(child_d + d < dis[child_v][1]) {
                    q.push({child_d + d, child_v, 1});
                    }
                }
            }
        }
    }
    cout<<dis[n][1]<<endl;
}