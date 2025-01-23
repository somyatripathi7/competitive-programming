
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=1;i<=n;i++) {
        int a,b;
        cin>>a>>b;
        v.push_back({a, 1});
        v.push_back({b,-1});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int curr = 0;
    for(auto it: v) {
        if(it.second == -1) {
            curr --;
        }
        else {
            curr++;
            ans = max(ans, curr);
        }
    }
    ans = max(ans, curr);
    cout<<ans<<endl;
}