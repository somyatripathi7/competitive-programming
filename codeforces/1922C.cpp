
#include <bits/stdc++.h>
using namespace std;

int help(vector<int> v, int x) {
    int n = v.size();
    int left = 0;
    int right = n-1;
    int ans = -1;
    while(left <= right) {
        int mid = (left + (right-left)/2);
        if(v[mid]<=x) {
            ans = mid;
            left = mid+1;
        }
        else
            right = mid-1;
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin>>n;
        vector<int> v(n+1, -1);
        for(int i=1;i<=n;i++) 
            cin>>v[i];
        vector<int> left;
        vector<int> right;
        set<int> r;
        right.push_back(1);
        r.insert(1);
        for(int i=2;i<n;i++) {
            if(v[i]-v[i-1]>v[i+1]-v[i]) {
                right.push_back(i);
                r.insert(i);
            }
        }
        for(int i=1;i<=n;i++) {
            if(r.find(i) == r.end())
                left.push_back(i);
        }
        int m; cin>>m;
            while(m--) {
            int x, y;
            cin>>x>>y;
            if(x<y) {
                int idx = lower_bound(left.begin(), left.end(), x) - left.begin();
                if(idx == n+1 || left[idx]>=y)
                    cout<<y-x<<endl;
                else
                    cout<<left[idx] - x + abs(v[y] - v[left[idx]])<<endl;
            }
            else {
                int idx = help(right, x);
                if(idx == 0 || right[idx]<=y)
                    cout<<x-y<<endl;
                else
                    cout<<x - right[idx] + abs(v[y] - v[right[idx]])<<endl;
            }
        }
    }
}