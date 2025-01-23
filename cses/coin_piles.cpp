#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<string> ans;
    for(int i=1;i<=n;i++) {
        int a, b;
        cin>>a>>b;
        if((a+b)%3!=0) {
            ans.push_back("NO");
        }
        else {
            if(a<b) swap(a,b);
            if(a>2*b)
            ans.push_back("NO");
            else
            ans.push_back("YES");
        }
    }
    for(int i=0;i<n;i++) {
        cout<<ans[i]<<endl;
    }
}