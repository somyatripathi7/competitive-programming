#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>> v;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=1;i<=n;i++) {
        int a,b;
        cin>>a>>b;
        v.push_back({a, -1, i});
        v.push_back({b, 1, i});
        q.push(i);
    }
    sort(v.begin(), v.end());
    vector<int> rooms(n+1, 0);
    int curr = 0;
    int ans = 0;
    for(auto it : v) {
        if(it[1] == -1) {
            curr++;
            rooms[it[2]] = q.top();
            q.pop();
            ans = max(ans, curr);
        }
        else {
            curr--;
            q.push(rooms[it[2]]);
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++) 
        cout<<rooms[i]<<" ";
    cout<<endl;
}