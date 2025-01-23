#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>> t;
    while(t--) {
    	int n; cin>>n;
    	vector<int> x(n), y(n), v(n);
    	for(int i=0;i<n;i++) cin>>x[i];
    	for(int i=0;i<n;i++) cin>>y[i];

	    for(int i=0;i<n;i++) v[i] = y[i] - x[i];
	    sort(v.begin(), v.end());


		int ans = 0;
		int l = 0; int r = n-1;
		while(l<r) {
			if((v[l] + v[r]) >= 0) {
				//cout<<v[l]<<" "<<v[r]<<" greater than 0"<<endl;
				ans ++;
				l++; r--;
			}
			else {
				l++;
			}
		}
		cout<<ans<<endl;
	}

}
