#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int N = 1e6+5; 

void factorise(int n, vector<int>& primes, map<int, int>& m) {
	int curr = 0;
	while(n > 1) {
		int div = primes[curr];
		if(n % div == 0) {
			m[div]++;
			n /= div;
		}
		else
			curr++;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    vector<bool> isPrime(N, true);
    isPrime[0] = false; isPrime[1] = false;
    vector<int> primes;

    for(int i=2;i<N;i++) {
    	if(isPrime[i]) {
    		primes.push_back(i);
    		for(int j = 2*i; j<N; j += i)
    			isPrime[j] = false;
    	}
    }

    while(t--) {
    	int n; cin>>n;
    	vector<int> v(n);
    	for(int i=0;i<n;i++) cin>>v[i];
    	map<int, int> m;
    	for(auto it: v) factorise(it, primes, m);

    	bool poss = true;
    	for(auto it: m) {
    		if(it.second % n != 0) {
    			poss = false;
    			break;
    		}
    	}

    	if(poss)
    		cout<<"YES"<<endl;
    	else
    		cout<<"NO"<<endl;

	}
}
