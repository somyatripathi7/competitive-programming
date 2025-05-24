#include<bits/stdc++.h>
using namespace std;
#define ll long long 

bool cmp(int a, int b, vector<int>& pre) {
    if(pre[a] !=  pre[b])
        return pre[a] > pre[b];
    return a < b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--) {
    	int n, q; cin>>n>>q;
        vector<int> v(n);
        vector<int> pre(n, 0);
        vector<pair<int, int>> queries;
        for(int i=0; i<n; i++) cin>>v[i];

        for(int i=1; i<=q; i++) {
            int l, r; cin>>l>>r;
			l--; r--;
            queries.push_back({l, r});
            pre[l] ++;
            if(r+1 < n) pre[r+1] --;
        }

        for(int i=1; i<n; i++) pre[i] = pre[i-1] + pre[i];

		for(int i=0;i<n;i++) cout<<" i is "<<i<<" pre is "<<pre[i]<<endl;

        vector<int> indices;
        for(int i=0;i<n;i++) indices.push_back(i);

        sort(indices.begin(), indices.end(), [&](int a, int b) {
                    return cmp(a, b, pre);
                });

        sort(v.begin(), v.end(), greater<int>());
        vector<int> arr(n, 0);
        for(int i=0;i<n;i++) {
            arr[indices[i]] = v[i];
        }

		for(int i=0;i<n;i++) cout<<" i is "<<i<<" arr is "<<arr[i]<<endl;

        vector<ll> prefix(n, 0);
        prefix[0] = arr[0];
        for(int i=1;i<n;i++) prefix[i] = prefix[i-1] + arr[i];

        ll ans = 0;
        for(auto it: queries) {
            ans += prefix[it.second];
            if(it.first > 0)
                ans -= prefix[it.first - 1];
        }

        cout<<ans<<endl;
    }
}
