
#include <bits/stdc++.h>
using namespace std;

long long help(int num, vector<int>& v) {
    int n = v.size();
    long long ans = 0;
    for(int i=0;i<n;i++) {
        if((1<<i) & num)
            ans += v[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> v;
    long long sum = 0;
    for(int i=1;i<=n;i++) {
        int a;
        cin>>a;
        v.push_back(a);
        sum += a;
    }
    long long ans = sum;
    for(int i=0;i<(1<<(n));i++) {
        long long a = help(i,v);
        long long b = sum-a;
        ans = min(ans,  abs(a-b));
    }
    cout<<ans<<endl;
}