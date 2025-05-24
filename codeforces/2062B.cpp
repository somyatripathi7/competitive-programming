#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	int n; cin>>n;
    	vector<int> v(n);
    	for(int i=0;i<n;i++) cin>>v[i];
    	bool ans = true;
    	for(int i=0;i<n;i++) {
    		int dis = max(2*i, 2*(n-i-1));
    		//cout<<" dis is "<<dis<<endl;
    		if(dis >= v[i]) {
    			ans = false;
    			break;
    		}
    	}

    	if(ans)
    		cout<<"YES"<<endl;
    	else
    		cout<<"NO"<<endl;	
    }
}
