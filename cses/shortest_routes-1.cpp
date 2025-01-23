#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<long,long>>> g(n+1);
    for(int i=1;i<=m;i++) {
        long long a,b,d;
        cin>>a>>b>>d;
        g[a].push_back({b,d});
    }
    priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> q;
    vector<long long> dis(n+1, -1);

    q.push({0, 1});
    while(!q.empty()) {
        long long v = q.top()[1];
        long long d = q.top()[0];
        q.pop();
        if(dis[v] != -1) continue;
        dis[v]=d;
        for(auto child : g[v]) {
            q.push({d+child.second, child.first});
        }
    }
    for(int i=1;i<=n;i++) {
        cout<<dis[i]<<" ";
    }
}