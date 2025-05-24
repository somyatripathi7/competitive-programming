#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
   	int t; cin>>t;
   	while(t--) {
   		int n, x;
   		cin >> n>> x;
   		ll s = 0;
   		for(int i = 0; i < n ; i ++) {
   			int a; cin >> a;
   			s += a;
   		}
   		if((n* 1LL * x) == s)
   			cout<<"YES"<<endl;
   		else
   			cout<<"NO"<<endl;
   	} 

}
