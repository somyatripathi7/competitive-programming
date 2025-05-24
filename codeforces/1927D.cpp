#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	int n; cin>>n;
    	vector<int> v(n+1);
    	for(int i=1; i<=n; i++) cin>>v[i];

    	for(int i=1;i<=n;i++) cout<<" input vector is "<<v[i]<<endl;

		vector<int> diff;
		for(int i=1; i<n; i++) {
			if(v[i] != v[i+1])
				diff.push_back(i);
		}

    	for(int i=0;i<diff.size();i++) cout<<" diff vector is "<<diff[i]<<endl;

    	int q; cin>>q;
    	cout<<" numer of queries is "<<q<<endl;
    	for(int j=1; j<=q; j++) {
    	    int l, r; 
    	    cin>>l>>r;
    	    cout << "Processing query " << j << ": " << l << " " << r << "\n";  // Debug
    	    int idx = lower_bound(diff.begin(), diff.end(), l) - diff.begin();
    	    if(idx != diff.size() &&  diff[idx]+1 <= r) {
    	        cout<< diff[idx] << " " << diff[idx] + 1 << "\n";
    	    }
    	    else {
    	        cout<< -1 << " " << -1 << "\n";
    	    }
    	    cout << "Finished query " << j << "\n";  // Debug
    	}
    }
}
