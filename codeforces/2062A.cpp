#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	string s; cin>>s;
    	int ans = 0;
    	for(auto c: s) {
    		if(c == '1') ans ++;
    	}
    	cout<<ans<<endl;	
    }
}
