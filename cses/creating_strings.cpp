#include <bits/stdc++.h>
using namespace std;

void permute(int i, string str, set<string>& s) {
    int n = str.size();
    s.insert(str);
    if(i==n-1) return;
    for(int j=i;j<n;j++) {
        swap(str[i], str[j]);
        permute(i+1, str, s);
        swap(str[i], str[j]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str;
    cin>>str;
    set<string> s;
    permute(0, str, s);
    cout<<s.size()<<endl;
    for(auto it: s)
        cout<<it<<endl;
}