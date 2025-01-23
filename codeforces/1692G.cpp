#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main () {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n, k; 
        cin >> n >> k;
        k++;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        int l = 0;
        long long ans = 0;
        for (int r = 1; r < n; r++) {
            if (2 * v[r] <= v[r - 1]) {
                if (r - l >= k) {
                    ans += (r - l - k + 1);
                }
                l = r; // Reset the window
            }
        }
        if (n - l >= k) {
            ans += (n - l - k + 1);
        }

        cout << ans << endl;
    }
}
