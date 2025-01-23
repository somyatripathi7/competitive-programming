#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int a1, a2, a4, a5; cin>>a1>>a2>>a4>>a5;
        int curr = 0;
        int ans = 0;
        for(int i=-100; i<=100;i++) {
        	if((a1 + a2) == i)
        		curr++;
        	if((a2 + i) == a4)
        		curr++;
        	if((i + a4) == a5)
        		curr++;
        	ans = max(ans, curr);
        	curr = 0;
        }

        cout<<ans<<endl; 
    }
}
