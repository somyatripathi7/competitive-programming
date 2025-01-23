#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        string str;
        cin>>str;
        set<char> s;
        int f = 0;
        int ans = str.size();
        for(int i=0;i<=25;i++) {
            int curr = 0;
            int temp = 0;
            for(int j=0;j<str.size();j++) {
                if(str[j] == i+'a') {
                    temp = max(temp, (int)log2(curr) + 1);
                    curr = 0;
                }
                else 
                    curr ++;
            }
            temp = max(temp, (int)log2(curr) + 1);
            ans = min(ans, temp);
        }
        cout<<ans<<endl;
    }
}