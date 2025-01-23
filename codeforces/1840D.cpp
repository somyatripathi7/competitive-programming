
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> v, int limit) {
    int n = v.size();
    int l = 0, r = 0;
    int curr = 0;
    int diff = 0;
    for(int i=1;i<n;i++) {
        if((v[i] - v[l]+1)/2 <= limit) {
            r = i;
        }
        else {
            if(curr<=1) {
                diff = max(diff, (v[r] - v[l]+1)/2);
                r = i;
                l = i;
                curr++;
            }
            else if(curr == 2) {
                diff = max(diff, (v[n-1] - v[l]+1)/2);
                break;
            }
        }
    }
    return diff<=limit;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin>>v[i];
        }
        sort(v.begin(), v.end());

        int low = 0;
        int high = v[n-1] - v[0];

        int ans = high;

        while(low<=high) {
            int mid = low + (high - low)/2;
            bool poss = check(v, mid);
            if (poss) {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        cout<<ans<<endl;

    }
}