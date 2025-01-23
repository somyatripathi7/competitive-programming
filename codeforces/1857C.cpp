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
        int l = (n*(n-1))/2;
        vector<int> v(l);
        for(int i=0;i<l;i++) cin>>v[i];

        sort(v.begin(), v.end());
        int curr = n-1;

        vector<int> ans;

        for(int i=0;i<l;) {
            ans.push_back(v[i]);
            i += curr;
            curr --;
        }

        ans.push_back(ans[ans.size() - 1]);

        for(auto it: ans) cout<<it<<" ";
        cout<<endl;

    }
}
