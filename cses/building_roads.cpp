#include <bits/stdc++.h>
using namespace std;

vector<int> par(1e5+1, 0);
vector<int> siz(1e5+1, 0);

void make(int a) {
    par[a] = a;
    siz[a] = 1;
}

int find(int a) {
    if(a==par[a]) return a;
    return par[a] = find(par[a]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(siz[b] > siz[a]) swap(a,b);
    par[b] = a;
    siz[a] += siz[b];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
        make(i);

    for(int i=1;i<=m;i++) {
        int a,b;
        cin>>a>>b;
        Union(a,b);
    }

    int count = 0;
    vector<pair<int,int>> ans;
    set<int> s;
    vector<int> parents;
    for(int i=1;i<=n;i++) {
        int par = find(i);
        if(s.find(par) == s.end()) {
            if(parents.size()>0) {
                ans.push_back({parents[0], par});
            }
            else
                parents.push_back(par);
            s.insert(par);
        }
    }
    cout<<ans.size()<<endl;
    for(auto it: ans) {
        cout<<it.first<<" "<<it.second<<endl;
    }
    

}
