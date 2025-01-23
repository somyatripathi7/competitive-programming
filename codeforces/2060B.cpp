#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
    	int n, m; cin>>n>>m;
    	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    	vector<vector<int>> v(n, vector<int> (m, 0));
    	for(int i = 0; i<n; i++) {
    		for(int j = 0; j<m; j++) {
    			int a; cin >> a;
    			q.push({a, i});
    			v[i][j] = a; 
    		}
    	}

    	vector<int> ans;
    	set<int> s;
    	int poss = 1;
    	int curr = 0;

    	while(!q.empty()) {
    	int idx = q.top()[1]; q.pop();
		if(s.size() < n) {
    		if(s.find(idx) != s.end()) {
    			poss = 0;
    			break;
    		}
    		else {
    			ans.push_back(idx);
    			s.insert(idx);
    		}
    	}
		else {
			if(idx != ans[curr]) {
				poss = 0;
				break;
			}
			else {
				curr ++;
				if(curr == n) curr = 0;
			}
		}
	}

    // if(poss) {
    // 	for(int j=0;j<m;j++) {
    // 		for(int i=1;i<ans.size();i++) {
    // 			int row = ans[i];
    // 			int prev = ans[i-1];
    // 			if(v[row][j] <= v[prev][j]) {
    // 				poss = 0;
    // 				break;
    // 			}
    // 		}
    // 	}
    // }

    if(poss) {
    	for(auto it: ans) cout<<(it + 1)<<" ";
    		cout<<endl;
    }
    else cout<<-1<<endl;
	}
}
