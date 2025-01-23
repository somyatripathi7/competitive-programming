#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin>> q;
    while(q--) {
    	int n, t; cin>>n>>t;
    	vector<int> v(n);
    	for(int i=0;i<n;i++) cin>>v[i];
    	sort(v.begin(), v.end());

    	//int idx = upper_bound(v.begin(), v.end(), t) - 1 - v.begin();
    	int curr = 0;
    	int idx = n-1;

    	int ans = 0;

    	while (idx >= 0) {
    	            // Skip elements that cannot fit with current `curr`
    	            if (v[idx] + curr > t) {
    	                idx--;
    	                continue;
    	            }
    	            // If it fits, count it and increment `curr`
    	            ans++;
    	            curr++;
    	            idx--;  // Move to the next element
    	      }

    	cout<<ans<<endl;



    }
}
