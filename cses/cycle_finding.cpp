#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=1;i<=m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }

    vector<long long> dis(n+1, 0);
    vector<int> par(n+1, -1);
    int x;
    for(int i=1;i<=n;i++) {
        x = -1;
        for(auto e: edges) {
            int u = e[0];
            int v = e[1];
            int c = e[2];
            if(dis[u]+c < dis[v]) {
                x = v;
                par[v] = u;
                dis[v] = dis[u] + c;
            }
        }
    }

    if(x==-1) {
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++) x = par[x]; 
        vector<int> cycle;
        for(int i=x; ;i=par[i]) {
            cycle.push_back(i);
            if(i==x && cycle.size()>1) 
                break;
        }
        reverse(cycle.begin(), cycle.end());
        for(auto it: cycle) {
            cout<<it<<" ";
        }
        cout<<endl;
    }
}