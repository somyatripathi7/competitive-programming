#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> degree(n+1, 0);
    map<vector<int>, int> edges;

    for(int i=1;i<=n-1;i++) {
        int a,b;
        cin>>a>>b;
        degree[a]++;
        degree[b]++;
        edges[{a, b}] = 0;
    }

    vector<vector<int>> arr;
    for(auto &it: edges) {
        int u = it.first[0];
        int v = it.first[1];
        it.second = degree[u] + degree[v];
        arr.push_back({it.second, it.first[0], it.first[1]});
    }

    sort(arr.begin(), arr.end());
    for(int i=1;i<=n;i++) degree[i]=0;
    int ans = 0;
    for(auto it: arr) {
        int u = it[1];
        int v = it[2];
        if(degree[u]==0 && degree[v]==0) {
            ans ++;
            degree[u]++;
            degree[v]++;
        }
    }
    cout<<ans<<endl;
}