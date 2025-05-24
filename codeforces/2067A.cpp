#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--) {
    	int x, y; cin>>x>>y;
    	int diff = y - x;
    	if((1 - diff)%9 == 0 && (1 - diff) >= 0) cout<<"YES"<<endl;
    	else cout<<"NO"<<endl;	
    }
}
