#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> v;
        set<int> s;
        for(int i=1;i<=n;i++) {
            int a;
            cin>>a;
            v.push_back(a);
            s.insert(i);
        }
        int flag = 1;
        int ans = 0;
        sort(v.begin(), v.end());
        for(auto i: v) {
            if(s.find(i) != s.end()) {
                s.erase(i);
            }
            else {
                if((i-1)/2 < *s.begin()) {
                    flag = 0;
                    break;
                }
                else {
                    ans ++;
                    s.erase(*s.begin());
                }
            }
        }
        if(flag == 1)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
    }
}