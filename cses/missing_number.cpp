#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n;
    cin>>n;
    long long sum = 0;
    for(int i=1;i<=n-1;i++) {
        int a;
        cin >> a;
        sum += a;
    }
    long long ans = (n*(n+1))/2-sum;
    cout<<ans<<endl;
}