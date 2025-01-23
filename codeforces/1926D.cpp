#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    vector<int> final_ans;
    while(t--) {
        int n;
        cin>>n;
        int ans = 0;
        unordered_map<long long,int> m;
        for(int i=1;i<=n;i++) {
            long long a;
            cin>>a;
            m[a]++;
        }
        for(auto it : m) {
            long long complement = ~it.first & 0x7FFFFFFF; ;
            if(m.find(complement) != m.end()) { 
                ans += max(it.second, m[complement]);
                m.erase(complement);
            }
            else   
                ans += it.second;
        }
        final_ans.push_back(ans);
    }
    for(auto it: final_ans)
        cout<<it<<endl;
}