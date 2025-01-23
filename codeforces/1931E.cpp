#include<bits/stdc++.h>
using namespace std;
#define ll long long 	

vector<int> help(int n) {
	int p = n;
	int len = 0, leading = 0;
	int flag = 0;
	while(p > 0) {
		if(p % 10 == 0 && flag == 0)
			leading ++;
		else if(p % 10 != 0) 
			flag = 1;
		len ++;
		p = p/10;
	}
	return {len, leading};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	int n, m; cin>>n>>m;
    	int non_zeroes = 0;
    	vector<pair<int, int>> arr;	
    	for(int i=0;i<n;i++) {
    		int a; cin>>a;
    		int len = help(a)[0];
    		int zeroes = help(a)[1];
    		arr.push_back({zeroes, len});
    	}

    	sort(arr.begin(), arr.end(), greater<pair<int, int>>());
    	for(int i=0;i<n;i++) {
    		if(i%2 == 0)
    			non_zeroes += arr[i].second - arr[i].first;
    		else
    			non_zeroes += arr[i].second;
    	}

    	if(non_zeroes > m)
    		cout<<"Sasha"<<endl;
    	else 
    		cout<<"Anna"<<endl;
    }
} 
