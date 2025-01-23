#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main () {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n; cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
       	int k = 1; long long s = v[0];
       	long long ans = 0;
       	for(int i=1;i<n;i++) {
       		if(v[i] > 0) {
       			cout<<" adding sum "<<s<<" with k "<<k<<endl;
       			ans += s*k;
       			k++;
       			s = v[i];	
       		}
       		else
       			s += v[i];
    	}

       	cout<<" adding sum "<<s<<" with k "<<k<<endl;
    	ans += s * 1LL * k;
    	cout<<ans<<endl;
	}
}