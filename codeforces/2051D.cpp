#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n; 
        ll x, y;
        cin >> n >> x >> y;
        
        vector<ll> v(n);
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }
        
        sort(v.begin(), v.end());
        ll ans = 0;

        cout<<" sum is "<<sum<<endl;
        
        // For each i, find valid j where:
        // x ≤ (sum - v[i] - v[j]) ≤ y
        // Rearranging: sum - y ≤ v[i] + v[j] ≤ sum - x
        for(int i = 0; i < n-1; i++) {
            // For a given v[i], we need v[j] where:
            // sum - y - v[i] ≤ v[j] ≤ sum - x - v[i]
            
            ll need_low = max(0LL, sum - y - v[i]);  // Lower bound for v[j]
            ll need_high = sum - x - v[i];           // Upper bound for v[j]
            
            auto low = lower_bound(v.begin() + i + 1, v.end(), need_low);
            auto high = upper_bound(v.begin() + i + 1, v.end(), need_high);
            cout<<" low is"<<(low - v.begin() - i - 1)<<" high is "<<(high - v.begin() - i - 1)<<endl;            
            if(low < high) {
                ans += high - low;
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}