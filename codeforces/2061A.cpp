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
    	int n; cin>>n;
    	int odd = 0;
    	for(int i=1;i<=n;i++) {
    		int a; cin>>a;
    		if(a % 2 != 0) odd++;
    	}
    	int ans = 0;
    	int even = n - odd;
    	if(even >=1)
    		ans = odd + 1;
    	else
    		ans = odd - 1;
    	cout<<ans<<endl;
    }	
}
