#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        int mi = INT_MAX;
        int idx = -1; 
        for(int i=0;i<n;i++) {
            cin>>v[i];
            if(v[i]<mi) {
                mi = v[i];
                idx = i;
            }
        }
        int flag = 1;
        for(int i=idx+1;i<n-1;i++) {
            if(v[i]>v[i+1]) {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
            cout<<idx<<endl;
        else
            cout<<-1<<endl;
    }
}