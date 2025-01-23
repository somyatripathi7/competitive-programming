#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>> t;
    while(t--) {
    	int n, t; cin>>n>>t;
    	vector<int> v(n), pre(n+1, INT_MAX), suff(n+1, INT_MIN);
    	pre[0] = -1;
    	suff[0] = n;
    	int total = 0;
    	for(int i=0;i<n;i++) {
    		cin>>v[i];
    		total += v[i];
    	}

    	int curr = 0;
    	for(int i=0;i<n;i++)  {
    		curr += v[i];
    		if(pre[curr] == INT_MAX)
    			pre[curr] = i;
    	}
    	curr = 0;
    	for(int i=n-1; i>=0; i--) {
    		curr += v[i];
    		if(suff[curr] == INT_MIN)
    			suff[curr] = i;
    	}

    	//for(int i=0;i<=n;i++) cout<<" pre for "<<i<<" is "<<pre[i]<<endl;

    	//for(int i=0;i<=n;i++) cout<<" suff for "<<i<<" is "<<suff[i]<<endl;

    	int ans = INT_MAX;

    	t = total - t;
    	for(int i=0;i<=t;i++) {
    		int front = pre[i];
    		int back = suff[t - i];
    		if(front != INT_MAX && back != INT_MIN && front < back) {
    			ans = min(ans, front+1 + n - back);
    		}
    	}

    	if(ans == INT_MAX)
    		cout<<-1<<endl;
    	else
    		cout<<ans<<endl;

    }
}
