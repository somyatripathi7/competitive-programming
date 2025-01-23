#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> v;
    for(int i=1;i<=n;i++) {
        int a;
        cin>>a;
        v.push_back(a);
    }
    set<int> s;
    for(auto it: v) {
        s.insert(it);
    }
    cout<<s.size()<<endl;
}