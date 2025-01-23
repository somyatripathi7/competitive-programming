#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const int MOD = 998244353;
const int N = 2e5;

vector<int> f(N + 1, 0);

void calculate() {
	f[0] = 1;
	for(int i=1;i<=N;i++) {
		f[i] = (f[i-1] * 1LL * i)%MOD;	
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	calculate();
	while(t--) {
		string s; cin>>s;

		int del = 0, curr = 0;
		int ways = 1;
		for(int i=1;i<s.size();i++) {
			if(s[i] == s[i-1])
				curr++;
			else {
				curr ++;
				ways = (ways * 1LL * curr)%MOD;
				del += (curr-1);
				curr = 0;	
			}
		}
		curr ++;
		ways = (ways * 1LL * curr)%MOD;
		del += curr-1;

		ways = (ways * 1LL * f[del])%MOD;
		cout<<del<<" "<<ways<<endl;

	}
}