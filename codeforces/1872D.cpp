#include<bits/stdc++.h>
using namespace std;
#define ll long long 	

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	int n, x, y;  cin>>n>>x>>y;
    	int l1 = n/x;
    	int l2 = n/y;
    	int l3 = n / ((x* 1LL * y)/__gcd(x, y));
    	l1 = l1 - l3;
    	l2 = l2 - l3;


    	ll suffix = ((l1)* 1LL*(2*n - l1 + 1))/2; 
    	ll prefix = (l2*1LL*(l2 + 1))/2;


    	ll ans = suffix - prefix;

    	cout<<ans<<endl;
    	
    	}
}
