#include<bits/stdc++.h>
using namespace std;
#define ll long long 
//check if k palindromes each of len l can be formed
// if l is even then check if there are k*(l/2) pairs of same characters
// if l is odd  then check if there are k*(l/2) pairs of same characters and k unique  
bool check(vector<int>v, int l, int k) {
	sort(v.begin(), v.end());
	long long pairs = 0;
	long long unique = 0;
	long long a = k * 1LL * (l/2);
	long long b = k * (l%2);

	for(auto it: v) {
		if(pairs >= a && unique >= b)
			return true;
		else if (pairs >= a)
			unique += it;
		else if(unique >= b)
			pairs += it/2;
		else {
			if(pairs + it/2 >= a) {
				pairs = a;
				it -= (a - pairs)*2;
				unique += it;
			}
			else {
				pairs += it/2;
				if(it % 2 != 0) unique++;
			}
		}
	}
	return pairs >= a && unique >= b;
}

int main () {
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--) {
		int n, k; cin>>n>>k;
		string s; cin>>s;
		vector<int> v(26,0);
		for(char c: s)
			v[c-'a']++;	

		int ans = 1;
		int low = 1;
		int high = n/k;
		while(low<=high) {
			int mid = (low + high)/2;
			if(check(v, mid, k)) {
				ans = mid;
				low = mid + 1;
			}
			else
				high = mid - 1;
		}	
		cout<<ans<<endl;
	}
}
