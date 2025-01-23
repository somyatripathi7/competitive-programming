#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {
    {0, 1}, 
    {0, -1}, 
    {1, 0}, 
    {-1, 0}
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    vector<vector<char>> g(n, vector<char>(m, '.'));
    pair<int, int> man;
    pair<int, int> end;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>g[i][j];
            if(g[i][j] == 'M')
                q.push({{0, i, j}});
            else if(g[i][j] == 'A')
                man = {i, j};
        }
    }

    vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
    vector<vector<pair<int,int>>> par(n, vector<pair<int, int>>(m, {-1, -1}));

    bool flag = false;
    string ans = "";

    //first bfs for monsters
    while(!q.empty()) {
        vector<int> curr = q.top();
        q.pop();
        int d = curr[0];
        int x = curr[1];
        int y = curr[2];
        if(d >= dis[x][y]) continue;
        dis[x][y] = d;
        for(auto dir: dirs) {
            int X = x + dir.first;
            int Y = y + dir.second;
            if(min(X,Y)<0 || X>=n || Y>=m || g[X][Y] == '#' || g[X][Y] == 'M' || dis[X][Y]<=d+1) continue;
            q.push({d+1, X, Y});
        }
    }

    //second dfs for man
    q.push({0, man.first, man.second, -1, -1});
    while(!q.empty()) {
        vector<int> curr = q.top();
        q.pop();
        int d = curr[0];
        int x = curr[1];
        int y = curr[2];
        int par_x = curr[3];
        int par_y = curr[4];
        if(d >= dis[x][y]) continue;
        dis[x][y] = d;
        if(min(par_x, par_y) >=0 && par_x<n && par_y<m)
            par[x][y] = {par_x, par_y};
        if(x==0 || y==0 || x==n-1 || y==m-1) {
            flag = true;
            end = {x, y};
            break;
        }
        for(auto dir: dirs) {
            int X = x + dir.first;
            int Y = y + dir.second;
            if(min(X,Y)<0 || X>=n || Y>=m || g[X][Y]=='#' || g[X][Y]=='M' || dis[X][Y]<=d+1) continue;
            q.push({d+1, X, Y, x, y});
        }
    }
    
    if(flag) {
        cout<<"YES"<<endl;
        cout<<dis[end.first][end.second]<<endl;
        string path;
        for(pair<int,int> curr = end; curr != man; curr = par[curr.first][curr.second]) {
            pair<int, int> p = par[curr.first][curr.second];
            int x_diff = curr.first - p.first;
            int y_diff = curr.second - p.second;
            if(x_diff == 1)
                path.push_back('D');
            else if(x_diff == -1)
                path.push_back('U');
            else if(y_diff == 1)
                path.push_back('R');
            else
                path.push_back('L');
        }
            reverse(path.begin(), path.end());
            for(auto c: path)
                cout<<c; 
    }
    else 
        cout<<"NO"<<endl;

}