#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
   		int t; cin >> t;
   		while(t--) {
   			string s;
   			cin>> s;
   			int c = 0;
   			bool ans = false;
   			for(int i = 0; i<s.size(); i++) {
   				char it = s[i];
   				if(it == '(')
   					c++;
   				else {
   					c--;
   					if(c == 0 && i != s.size() - 1) {
   						ans = true;
   						break;
   					}
   				}

   			}
   			if(ans) cout<<"YES"<<endl;
   			else cout<<"NO"<<endl;
   		}
   	}

