#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        set<int> zero;
        set<int> one;
        for(int i=1;i<=n;i++) {
            int x, y; cin>>x>>y;
            if(y==0) {
                zero.insert(x);
            }
            else {
                one.insert(x);
            }
        }

        long long ans = 0;
        for(auto x: one) {
            if(zero.find(x) != zero.end()) {
                ans += one.size() - 1;
            }
                if(zero.find(x-1) != zero.end() && zero.find(x+1) != zero.end()) 
                    ans++;
        }

        for(auto x: zero) {
            if(one.find(x) != one.end()) {
                ans += zero.size() - 1;
            }
                if(one.find(x-1) != one.end() && one.find(x+1) != one.end()) 
                    ans++;
        }
        cout<<ans<<endl;

    }
}