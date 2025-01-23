#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<pair<long long, long long>> v;
        for(int i=0;i<n;i++) {
            long long x, y;
            cin>>x>>y;
            v.push_back({x, y});
        }
        long long x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        long long d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        bool flag = true;
        for(auto i: v) {
            long long curr = (i.first - x2)*(i.first - x2) + (i.second - y2)*(i.second - y2);  
            if(curr<=d) {
                flag = false;
                break;
            }
        }
        if(flag) 
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
