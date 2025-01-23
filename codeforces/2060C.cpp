#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	int n, k; cin>>n>>k;
    	vector<int> v(n);
    	for(int i=0;i<n;i++) {
    		cin>>v[i];
    	}

    	int pairs = 0;
    	sort(v.begin(), v.end());
    	int l = 0, r = n-1;
    	while(l<r) {
    		int sum = v[l] + v[r];
    		if(sum==k) {
    			pairs++;
    			l++;
    			r--;
    		}
    		else if(sum > k)
    			r -- ;
    		else l++;
    	}

    	cout<<pairs<<endl;


    }
}
