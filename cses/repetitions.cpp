#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    int ans = 0;
    int curr = 1;
    int n = s.size();
    for(int i=1;i<n;i++) {
        if(s[i]==s[i-1])    
            curr++;
        else {
            ans = max(ans, curr);
            curr = 1;
        }   
    }
    ans = max(ans, curr);
    cout<<ans<<endl;
}