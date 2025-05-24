#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	int n; cin>>n; string str; cin>>str;

    	map<int, set<int>> s;
    	int curr = 0;
    	for(int i=0;i<n;i++) {
    		curr = 0;
    		for(int j=i;j<n;j++) {
    			curr += str[j] - 'a' + 1;
    			s[i].insert(curr);
    		}
    	}

    	for(int )
    	cout<<count<<endl;
    	string ans = "";
    	while(count > 0) {
    		if(count >= 26) {
    			ans.push_back('z');
    			count -= 26;
    		}
    		else {
    			ans.push_back('a' + (count-1));
    			count = 0;
    		}
    	}

    	cout<<ans<<endl;
    }
}
