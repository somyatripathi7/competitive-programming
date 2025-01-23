#include<bits/stdc++.h>
using namespace std;
#define ll long long 	

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
    	int a, b, k; cin>>a>>b>>k;
    	vector<int> boys_count(a+1, 0); // number of times a boy is present in a pair
    	vector<int> girls_count(b+1, 0);
    	vector<int> boys_pos(k+1, 0); // which boy is present in pair i
    	vector<int> girls_pos(k+1, 0);

    	for(int i=1;i<=k;i++) {
    		int boy; cin>>boy;
    		boys_pos[i] = boy;
    		boys_count[boy] ++;
    	}

    	for(int i=1;i<=k;i++) {
    		int girl; cin>>girl;
    		girls_pos[i] = girl;	
    		girls_count[girl]++;
    	}

        map<int, vector<int>> m;
        for(int i=1;i<=k;i++) {
            // cout<<" pair number "<<i<<"  boy is "<<boys_pos[i]<<" girl is "<<girls_pos[i]<<endl;
            m[i] = {boys_pos[i], girls_pos[i]};
        }	

        // for(int i=1;i<=a;i++) cout<<" boys count for boy "<<i<<" is "<<boys_count[i]<<endl;
        // for(int i=1;i<=b;i++) cout<<" girls count for girl "<<i<<" is "<<girls_count[i]<<endl;

        int ans = 0;
        int i = 0;
        for(auto it: m) {
            int boy = it.second[0];
            int girl = it.second[1];
            int available = k;
            int not_possible = boys_count[boy] + girls_count[girl] - 1;
            ans += (available - not_possible);
        }
       
        ans /= 2;

        cout<<ans<<endl;
    }
}
