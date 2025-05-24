#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--) {
    	string s; cin>>s;
    	int n = s.size();
    	int l = 0; int r = 0;
    	for(int i=1; i<n ;i++) {
    		if(s[i] == s[i-1])
    			r++;
    		else {
    			//cout<<" l is "<<l<<" r is "<<r<<endl;
    			for(int j=l+1; j<=r; j+=2) {
    				set<char> used;
    				if(j-1 >= 0)
    					used.insert(s[j-1]);
    				if(j+1 < n)
    					used.insert(s[j+1]);
    				//for(auto it: used) cout<<" used "<<it<<endl;
    				for(char c = 'a' ; c<='c' ; c++) {
    					if(used.find(c) == used.end()) {
    						s[j] = c;
    						break;
    					}
    				}
    			}
    			l = i;
    			r = i;
    		}
    	}

		for(int j=l+1; j<=r; j+=2) {
			set<char> used;
			if(j-1 >= 0)
				used.insert(s[j-1]);
			else if(j+1 < n && s[j+1] == 'a')
				used.insert(s[j+1]);
			for(char c = 'a' ; c<='c' ; c++) {
				if(used.find(c) == used.end()) {
					s[j] = c;
					break;
				}
			}
		}

		cout<<s<<endl;


    }
}
