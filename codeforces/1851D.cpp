#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<long long> v(n);
        for(int i=1;i<n;i++)
            cin>>v[i];
        vector<long long> m(n+1);
        int x = 0;

        if(v[1]>n)
            x = v[1];
        else
            m[v[1]] = 1;

        for(int i=2;i<n;i++) {
            int diff = v[i] - v[i-1];
            if(diff>n)
                x = diff;
            else
                m[diff]++;
        }

        long long sum = 0;
        int count = 0;
        int flag = 0;
        for(int i=1;i<=n;i++) {
            if(m[i]>1) {
                flag = -1;
                break;
            }
            else if(m[i]==0) {
                sum += i;
                count++;
                if(count>2) {
                    flag = -1;
                    break;
                }
            }
        }

        if(((sum == x && count==2) || (sum==n && count == 1)) && flag != -1)
            flag = 1;
        else
            flag = 0;

        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

}