#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin>>n;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) {
            cin>>v[i];
            if(i%2 != 0)
                v[i] = -1*v[i];
        }
        set<long long> s;
        long long curr = 0;
        int flag = 0;
        for(int i=1;i<=n;i++) {
            curr+=v[i];
            if(curr == 0 || s.find(curr) != s.end()) {
                flag = 1;
                break;
            }
            s.insert(curr);
        }
        if(flag) 
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}