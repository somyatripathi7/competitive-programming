
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        long long n; cin>>n;
        vector<long long> bits;
        long long num = n;
        int curr = 0;
        while(num>0) {
            if(num & 1)
                bits.push_back(curr);
            curr++;
            num = num>>1;
        }

        vector<long long> ans;
        ans.push_back(n);
        for(int i=0;i<bits.size();i++) {
            if((n - (1LL<<bits[i])) == 0) continue;
            ans.push_back(n - (1LL<<bits[i]));
        }
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<endl;
        for(auto it: ans) 
            cout<<it<<" ";
        cout<<endl;
    }
}