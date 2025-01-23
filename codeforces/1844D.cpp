#include <bits/stdc++.h>
using namespace std;

void help(set<char>& se, int distinct) {
    se.insert('a');
    if(distinct>=2)
        se.insert('b');
    if(distinct >= 3)
        se.insert('c');
    if(distinct >= 4)
        se.insert('d');
    if(distinct >= 5)
        se.insert('e');
}

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int div1 = 1;
        for(int i=1;i*i<=n;i++) {
            if(n%i == 0) div1 = i;
        }
        int div2 = n/div1;
        if(div1 < div2) swap(div1, div2);

        set<char> se;
        help(se, 5);
        vector<vector<char>> g(div1, vector<char>(div2, '*'));

        string ans;
        for(int i=0;i<div1;i++) {
            for(int j=0;j<div2;j++) {
                if(i-1>=0 && g[i-1][j]!='*')
                    se.erase(g[i-1][j]);

                if(i+1<div1 && g[i+1][j]!='*')
                    se.erase(g[i+1][j]);

                if(j-1>=0 && g[i][j-1]!='*')
                    se.erase(g[i][j-1]);

                if(j+1>=0 && g[i][j+1]!='*')
                    se.erase(g[i][j+1]);

                ans.push_back(*se.begin());
                g[i][j] = *se.begin();
                help(se, 5);
            }            
        }
        cout<<ans<<endl;
    }
}