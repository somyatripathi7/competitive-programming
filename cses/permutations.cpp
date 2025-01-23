
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    if (n==1) {
        cout<<"1"<<endl;
    }
    else if(n<=3) {
        cout<<"NO SOLUTION"<<endl;
    }
    else if(n==4) {
        cout<<"2 4 1 3"<<endl;
    }
    else {
        vector<int> v(n+1,0);
        int c = 1;
        for(int i=1;i<=n; i+=2) {
            v[i] = c++;
        }
        c = (n+1)/2 + 1;
        for(int i=2;i<=n;i+=2) {
            v[i] = c++;
        }
        for(int i=1;i<=n;i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
}