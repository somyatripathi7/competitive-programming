#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	int n; cin>>n;
    	vector<int> a(n), b(n);
    	for(int i=0;i<n;i++) cin>>a[i];
    	for(int i=0;i<n;i++) cin>>b[i];
    	vector<int> diff(n);
    	for(int i=0;i<n;i++) diff[i] = a[i] - b[i];

    	int ma = INT_MIN;
    	for(auto it: diff) ma = max(it, ma);

    	vector<int> ans;
    	for(int i=0;i<n;i++) {
    		if(diff[i] == ma)
    			ans.push_back(i+1);
    	}

    	cout<<ans.size()<<endl;
    	for(auto it: ans) cout<<it<<" ";
    	cout<<endl;

    }
}
