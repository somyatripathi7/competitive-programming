#include<bits/stdc++.h>
using namespace std;
using lol=long long int;
#define endl "\n"
 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int _=1;
cin>>_;
while(_--)
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> f(n,0);
    int tmpk=k;
    for(int i=0;i<n && tmpk>0;i++)
    {
        if(k%2==s[i]-'0')
        {
            f[i]=1;
            tmpk--;
        }
    }
    f[n-1]+=tmpk;
    for(int i=0;i<n;i++)
    {
        if((k-f[i])%2==1)   s[i]='1'-(s[i]-'0');
    }
    cout<<s<<endl;
    for(auto& e:f)  cout<<e<<" ";
    cout<<endl;
}
return 0;
}