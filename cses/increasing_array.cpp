#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> v;
    for(int i=1;i<=n;i++) {
        int a;
        cin>>a;
        v.push_back(a);
    }
    long long ans = 0;
    for(int i=0;i<n-1;i++) {
        ans += max(0, v[i]-v[i+1]);
        v[i+1] = max(v[i+1], v[i]);
    }
    cout<<ans<<endl;
}