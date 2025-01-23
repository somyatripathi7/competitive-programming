#include<bits/stdc++.h>
using namespace std;
#define ll long long 	

vector<ll> help(ll n) {
	ll two = 0, five = 0;
	int p = n;
	while(n > 0 && n%5 == 0) {
		five ++;
		n = n/5;
	}
	while(p > 0 && p%2 == 0) {
		two ++;
		p = p/2;
	}
	return {two, five};
}

ll solve(ll two, ll five, ll n) { 
	ll power = 0, curr = 0;
	if(two <= five)	power = min((ll)log2(n), abs(five - two));
	else	power = min((ll)(log(n)/log(5.0)), abs(five - two));

	if(two <= five)	curr = pow(2, power);
	else	curr = pow(5, power);

	while(curr * 10 <= n)
		curr = curr * 10;

	ll q = n / curr;
	return curr * q;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	ll n, m; cin>>n>>m;
    	vector<ll> powers = help(n);

    	ll ans = n * solve(powers[0], powers[1], m);
    	cout<<ans<<endl;
    }
}
