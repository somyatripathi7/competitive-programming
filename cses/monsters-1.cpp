
#include <bits/stdc++.h>
using namespace std;

vector<pair<vector<int>, char>> dirs = {
    {{0, 1}, 'R'}, 
    {{0, -1}, 'L'}, 
    {{1, 0}, 'D'}, 
    {{-1, 0}, 'U'}
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    priority_queue<pair<vector<int>, string>, vector<pair<vector<int>, string>>, greater<pair<vector<int>, string>>> q;
    vector<vector<char>> g(n, vector<char>(m, '.'));

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>g[i][j];
            if(g[i][j] == 'A') {
                q.push({{0,i,j}, "" });
            }
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    string ans = "";

    while(!q.empty()) {
        vector<int> curr = q.top().first;
        string path = q.top().second;
        q.pop();
        int x = curr[1];
        int y = curr[2];
        int dis = curr[0];
        //cout<<" x is "<<x<<" y is "<<y<<"  dis is "<<dis<<" char is "<<g[x][y]<<endl;
        if(vis[x][y] || g[x][y]=='M') continue;
        else if(g[x][y] == '.') {
            if(min(x,y) == 0 || x==n-1 || y==m-1) {
                ans = path;
                break;
            }
        }
        vis[x][y] = true;
        for(auto dir: dirs) {
            int X = x + dir.first[0];
            int Y = y + dir.first[1];
            if(min(X,Y)<0 || X>=n || Y>=m || g[X][Y]=='#') continue;
            path.push_back(dir.second);
            q.push({{dis+1, X, Y}, path});
            path.pop_back();
        }
    }
    if(ans.size()>0) {
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}