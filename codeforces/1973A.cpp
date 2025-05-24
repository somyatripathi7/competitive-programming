#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--) {
        int a, b, c; cin>>a>>b>>c;
        if((a+b+c)%2 != 0) {
            cout<<-1<<endl;
            continue;
        }
        priority_queue<int> q;
        if(a > 0) q.push(a);
        if(b > 0) q.push(b);
        if(c > 0) q.push(c);
        int ans = 0;
        while(q.size() > 1) {
            int curr = q.top(); q.pop();
            int curr1 = q.top(); q.pop();
            curr --; curr1 --;
            ans ++;
            if(curr1 > 0) q.push(curr1); 
            if(curr > 0) q.push(curr);
        } 

        cout<<ans<<endl;
    }
}

