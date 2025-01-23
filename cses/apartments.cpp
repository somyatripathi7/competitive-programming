#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> a;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        a.push_back(x);
    } 
    for(int i=0;i<m;i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(v.begin(), v.end());
    int ans = 0;
    int upper = 0, lower = 0;
    while(upper<n && lower<m) {
        int left = a[upper]-k;
        int right = a[upper]+k;
        if(v[lower]>=left && v[lower]<=right) {
            ans++;
            upper++;
            lower++;
        }
        else if(v[lower]>right) {
            upper++;
        }
        else 
            lower++;
    }
    cout<<ans<<endl;
}