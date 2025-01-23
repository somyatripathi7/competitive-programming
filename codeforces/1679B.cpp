#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
    	int n, q; cin>>n>>q;
    	vector<int> v(n+1);
    	ll sum = 0;
    	map<int, int> m;
    	set<int> s;
    	for(int i=1;i<=n;i++) {
    		cin>>v[i];
    		sum += v[i];
    		m[i] = v[i];
    	}

    	int last = -1;	

    	for(int i=1; i<=q; i++) {
    		int t; cin>>t;
    		if(t==1) {
    			int pos, x; cin>>pos>>x;
				if(s.find(pos) != s.end() || last == -1) {
					sum += x - m[pos];
					m[pos] = x;
				}
				else {
					sum += x - last;
					m[pos] = x;
				}
				s.insert(pos);
    		}
    		else {
    			int x; cin>>x;
    			sum = n*1LL*x;
    			last = x;
    			s.clear();
    		} 
    		cout<<sum<<endl;
    	}	

    }
}
