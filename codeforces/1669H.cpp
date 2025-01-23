#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        vector<int> v;
        for(int i=1;i<=n;i++) {
            int a;
            cin>>a;
            v.push_back(a);
        }
        vector<int> bits(31, 0);
        int ans = 1<<31 - 1;
        for(auto it: v) {
            ans = ans & it;
            for(int i=0;i<=30;i++) {
                if(!(it&(1<<i)))
                    bits[i]++;
            }
        }
        for(int i=30;i>=0;i--) {
            if(bits[i] <= k) {
                ans |= 1<<i;
                k -= bits[i];
            }
        }
        cout<<ans<<endl;
    }
}