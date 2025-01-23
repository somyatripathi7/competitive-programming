#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n, idx;
        cin>>n>>idx;
        vector<int> v;
        int x = 0;
        for(int i=0;i<n;i++) {
            int a;
            cin>>a;
            v.push_back(a);
            if(a>v && x==)
        }
        swap(v[idx-1], v[0]);
        for(auto it: v) {
            cout<<it<<" "<<" *";
        }
        int ans = 0;
        for(int i=1;i<n;i++) {
            if(v[i-1]>v[i]) {
                ans++;
                v[i] = v[i-1];
            }
            else
                break;
        }
        cout<<ans<<endl;
    }
}
