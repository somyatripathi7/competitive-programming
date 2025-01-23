#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int two = 0;
        int three = 0;
        int sum = 0;
        for(char c : s) {
            if(c=='2')
                two++;
            else if(c=='3')
                three++;
            sum+=(c-'0');
        }
        cout<<"sum is "<<sum<<endl;
        int rem = sum%9;
        cout<<rem<<endl;
        if(rem == 0 || (rem == 7 && two>=1) || (rem == 3 && three>=1) || (rem == 1 && two>=1 && three>=1))
            cout<<"YES"<<endl;
        else    
            cout<<"NO"<<endl;
    }
}
