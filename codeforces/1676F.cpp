#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        vector<int> v(n+1);
        map<int, int> m;
        for(int i=1;i<=n;i++) { 
            cin>>v[i];
            m[v[i]]++;
        }

        vector<int> arr;
        for(auto it: m) {
            if(it.second>=k)
                arr.push_back(it.first);
        }

        int ans = -1;
        int ans_l = 0, ans_r = 0;

        if (arr.size()>0) {
            int l = arr[0];
            int r = arr[0]; 
            for(int i=1;i<arr.size();i++) {
                if(arr[i] - arr[i-1]==1)
                    r = arr[i];
                else {
                    if(r-l>ans) {
                        ans = r - l;
                        ans_l = l;
                        ans_r = r;
                    }
                    l = arr[i];
                    r = arr[i];
                }
            }
            if(r-l>ans) {
                ans = r - l;
                ans_l = l;
                ans_r = r;
            }
        }
        
        if(ans !=-1) 
            cout<<ans_l<<" "<<ans_r<<endl;
        else
            cout<<ans<<endl;
    }
}