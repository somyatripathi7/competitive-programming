#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;

    while(t--) {
    	int n, k1, k2; cin>>n>>k1>>k2;
    	int op = k1 + k2;

    	vector<int> a(n);
    	vector<int> b(n);

    	for(int i=0; i<n; i++) cin>>a[i];	
    	for(int i=0; i<n; i++) cin>>b[i];

    	priority_queue<int> q;

    	for(int i=0; i<n; i++) q.push(abs(a[i] - b[i]));

    	while(op > 0) {
    		int curr = q.top(); q.pop();
    		op --;
    		q.push(abs(curr - 1));	
    	}

    	ll ans = 0;
    	while(!q.empty()) {
    	 	int curr = q.top(); q.pop();
    	 	ans += curr * 1LL * curr;		
    	} 

    	cout<<ans<<endl;
    }
}
