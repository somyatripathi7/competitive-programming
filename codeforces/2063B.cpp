#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	//missed that the operation has to be performed only once
    	int n, l, r; cin>>n>>l>>r;
    	vector<int> v(n);
    	for(int i=0;i<n;i++) cin>>v[i];

    	vector<int> pre;
    	vector<int> suff;
		for(int i=0;i<r;i++) pre.push_back(v[i]);    	
		for(int i=l-1;i<n;i++) suff.push_back(v[i]);    	
    	sort(pre.begin(), pre.end());
    	sort(suff.begin(), suff.end());
    	int k = r-l+1;

    	ll ans = LONG_LONG_MAX;
    	ll curr = 0;
    	for(int i=0;i<k;i++) curr += pre[i];
    	ans = min(ans, curr);
    	for(int i=k;i<pre.size();i++) {
    		curr -= pre[i-k];
    		curr += pre[i];
    		ans = min(ans, curr);
    	}

    	curr = 0;
    	for(int i=0;i<k;i++) curr += suff[i];
    	ans = min(ans, curr);
    	for(int i=k;i<suff.size();i++) {
    		curr -= suff[i-k];
    		curr += suff[i];
    		ans = min(ans, curr);
    	}

    	cout<<ans<<endl;

    }
}
