#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> v;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> arr;
    arr.push_back(v[0]);
    for(int i=1;i<n;i++) {
        int idx = upper_bound(arr.begin(), arr.end(), v[i]) - arr.begin();
        if(idx>=arr.size()) {
            arr.push_back(v[i]);
        }
        else {
            arr[idx] = v[i];
        }
    }
    cout<<arr.size()<<endl;

}