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
    long long neg = 0;
    long long curr = 0;
    long long ans = INT_MIN;
    for(int i=0;i<n;i++) {
        curr += v[i];
        ans = max({ans, curr, curr-neg});
        neg = min(neg, curr);
    }
    cout<<ans<<endl;
}