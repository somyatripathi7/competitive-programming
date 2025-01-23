#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        int n; string s1, s2;
        cin>>n>>s1>>s2;
        int a_1 = INT_MAX;
        int c_1 = INT_MIN;
        int a_2 = INT_MAX;
        int c_2 = INT_MIN;
        int a = 0, b = 0, c =0;
        for(int i=0;i<s1.size();i++) {
            if(s1[i] == 'a') {
                a++;
                a_1 = min(a_1, i);
            }
            else if(s1[i] == 'c') {
                c++;
                c_1= max(c_1, i);
            }
            else
                b++;
        } 

        for(int i=0;i<s2.size();i++) {
            if(s2[i] == 'a') {
                a--;
                a_2 = min(a_2, i);
            }
            else if(s2[i] == 'c') {
                c--;
                c_2= max(c_2, i);
            }
            else
                b--;
        }

        if(a!=0 || b!=0 || c!=0 || a_1 > a_2 || c_1 < c_2)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl; 
    }
}