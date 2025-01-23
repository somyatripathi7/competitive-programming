
#include <bits/stdc++.h>
using namespace std;

bool help(long long time, vector<int>& v, int t) {
    int c = 0;
    for(auto it : v) {
        c += (time/it);
        if(c>=t)
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,t;
    cin>>n>>t;
    vector<int> v;
    for(int i=1;i<=n;i++) {
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    long long ans = INT_MAX;
    long long left = 0;
    long long right = t*1LL*v[0];
    while(left<=right) {
        long long mid = (left + right)/2;
        bool poss = help(mid, v, t);
        if(poss) {
            ans = mid;
            right = mid - 1;
        }
        else 
            left = mid + 1;
    }
    cout<<ans<<endl;
}