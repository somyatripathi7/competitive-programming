#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
   	int t; cin>>t;
   	while(t--) {
        int n; cin>>n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin>>v[i];
        sort(v.begin(), v.end());
        int l_zero = INT_MAX, r_zero = -1, l_one = INT_MAX, r_one = -1;
        int ans = n;
        for(int i = 0; i < n; i++) {
            if(v[i]%2 == 0) {
                l_zero = min(l_zero, i);
                r_zero = max(i, r_zero);
            }
            else {
                l_one = min(l_one, i);
                r_one= max(i, r_one);
            }
        }
        if(l_zero != INT_MAX) {
            ans = min(ans, n - (r_zero - l_zero + 1));
        }
        if(l_one != INT_MAX) {
            ans = min(ans, n - (r_one - l_one + 1));
        }
        cout<<ans<<endl;
   	}

   }
