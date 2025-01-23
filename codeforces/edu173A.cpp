#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    vector<long long> v;
    for(int i=1;i<=t;i++) {
        long long x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<v.size();i++) {
        long long num = v[i];
        int steps = 0;
        while(num>3) {
            num/= 4;
            steps++;
        }
        cout<<(1<<steps)<<endl;
    }
}