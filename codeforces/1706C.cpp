#include <bits/stdc++.h>
using namespace std;

long long help(vector<int>&v, int idx) {
    int n = v.size();
    long long ans = 0;
    for(int i=idx; i<n-1; i+=2) {
            ans += max(0 , max(v[i-1], v[i+1]) - v[i] + 1);
    }
    return ans;
}

long long help(int i, long long last, long long last_to_last) {
    

}

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++) {
            int a; cin>>a;
            v.push_back(a);
        }

        long long ans = help(v, 1);
        if(n%2 == 0)
            ans = min(ans, help(v, 2)); 

        cout<<ans<<" * "<<endl;
    }
}