#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main () {
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		vector<int> a(n);
		vector<int> b(n);
		for(int i=0;i<n;i++) cin>>a[i];	
		for(int i=0;i<n;i++) cin>>b[i];

		long long sum = 0;
		for(int i=0;i<n-1;i++) {
			if(a[i] - b[i+1]>0)
				sum += a[i] - b[i+1];
		}	
		sum += a[n-1];
		cout<<sum<<endl;
	}
}

