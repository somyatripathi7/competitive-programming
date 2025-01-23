#include<bits/stdc++.h>
using namespace std;
#define ll long long 	

bool solve() {
	int n, m;	
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	//track top 3 days for each activity along with the day
    	int n; cin>>n;
    	vector<pair<int, int>> a, b, c;
    	for(int i=0;i<3;i++) {
    		for(int j=0;j<n;j++) {
    			int x; cin>>x;
    			if(i==0) {
    				a.push_back({x, j});
    			}
    			else if(i==1) {
    				b.push_back({x, j});
    			}
    			else {
    				c.push_back({x, j});
    			}
    		}
    	}

    	sort(a.begin(), a.end(), greater<pair<int, int>>());
    	sort(b.begin(), b.end(), greater<pair<int, int>>());
    	sort(c.begin(), c.end(), greater<pair<int, int>>());

    	int ans = 0;

    	for(int i=0;i<3;i++) {
    		for(int j=0;j<3;j++) {
    			for(int k=0;k<3;k++) {
    				if(a[i].second == b[j].second || a[i].second == c[k].second || b[j].second == c[k].second)
    					continue;
    				ans = max(ans, a[i].first + b[j].first + c[k].first);
    			}
    		}
    	}

    	cout<<ans<<endl;
    }
}
