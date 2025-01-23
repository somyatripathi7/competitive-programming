#include<bits/stdc++.h>
using namespace std;
#define ll long long 	

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	int n; cin>>n;
    	vector<int> v(n+1);
    	priority_queue<int> high;
    	priority_queue<int, vector<int>, greater<int>> low;
    	set<int> s;
    	for(int i=1;i<=n;i++) {
    		cin>>v[i];
    		low.push(v[i]);
    		high.push(v[i]);
    		s.insert(v[i]);
    	}	


    	int l = 1, r = n;
    	bool poss = 0;
    	int curr = 0;
    	while(l<r) {
    		while(!low.empty() && s.find(low.top()) == s.end()) low.pop();
    		while(!high.empty() && s.find(high.top()) == s.end()) high.pop();
    		int smallest = low.top();
    		int largest = high.top();
    		if(v[l] != smallest && v[l] != largest && v[r] != smallest && v[r] != largest) {
    			poss = 1;
    			break;
    		}
    		else {
    			s.erase(v[l]);
    			s.erase(v[r]);
    			l++;
    			r--;
    		}
    	}

    	if(poss)	cout<<l<<" "<<r<<endl;
    	else 	cout<<-1<<endl;

    }
}
