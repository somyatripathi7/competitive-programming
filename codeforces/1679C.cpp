#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, q; cin>>n>>q;
    set<int> r;
    set<int> c;
    for(int i=1;i<=q;i++) {
        int t; cin>>t;
        if(t == 1 || t == 2) {
            int x, y; cin>>x>>y;
            if(t==1) {
                r.insert(x);
                c.insert(y);
            }
            else {
                r.erase(x);
                c.erase(y);
            }
        }
        else {
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;
            int flag = 0;
            if(x1>x2) swap(x1, x2);
            if(y1>y2) swap(y1, y2);
            auto r_attack = r.lower_bound(x1);
            if(r_attack != r.end() && *r_attack <= x2)
                flag = 1;
            auto c_attack = c.lower_bound(y1);
            if(c_attack != c.end() && *c_attack <= y2)
                flag = 1;

            if (flag)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
}