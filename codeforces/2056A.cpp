#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const int MOD = 1e9+7;

int main () {
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--) {
		int n, m; cin>>n>>m;
		int mi_x = INT_MAX;
		int ma_x = INT_MIN;
		int mi_y = INT_MAX;
		int ma_y = INT_MIN;
		int curr_x = 0;
		int curr_y = 0;
		for(int i=0;i<n;i++) {
			int x, y; cin>>x>>y;
			curr_x += x;
			curr_y += y;
			mi_y = min(curr_y, mi_y);
			ma_y = max(curr_y+m,ma_y);
			mi_x = min(curr_x, mi_x);
			ma_x = max(curr_x+m, ma_x);
		}

		cout<<(2*((ma_y-mi_y)+(ma_x-mi_x)))<<endl;	
	}
}
