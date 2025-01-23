#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        string s; cin>>s;
        int curr = 0;
        int flag = 0;
        queue<int> q;
        for(int i=0;i<n;i++) {
            char ch = s[i];
            curr += ch == '(' ? 1 : -1;
            if(curr == 1 && flag == -1) {
                q.push(i-1);
            }
            else if (curr == -1 && flag == 1) {
                q.push(i-1);
            }
            if(curr>0)
                flag = 1;
            else if(curr < 0)
                flag = -1;

        }



        if(curr!=0) {
            cout<<-1<<endl;
        }

        else {
            if(q.size()==0) cout<<1<<endl;
            else cout<<2<<endl;
            int color = 1;
            for(int i=0;i<n;i++) {
                cout<<color<<" ";
                if(!q.empty() && i == q.front()) {
                    color = color == 1?2:1;
                    q.pop();
                }
            }
            cout<<endl;
        }
    }
}