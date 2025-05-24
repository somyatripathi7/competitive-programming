#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--) {
    	int n; cin>>n;
    	vector<pair<int, int>> v;
    	for(int i=0;i<n;i++) {
    		int l, r; cin>>l>>r;
    		v.push_back({l, -1});
    		v.push_back({r, 1});
    	}
    	sort(v.begin(), v.end());

    	bool poss = true;

    	int curr = 0;
    	for(auto it: v) {
    		if(it.second == -1)
    			curr ++;
    		else
    			curr --;
    		if(curr > 2) {
    			poss = false;
    			break;
    		}
    	}

    	if(poss) cout<<"YES"<<endl;
    	else	cout<<"NO"<<endl;

    }
}
