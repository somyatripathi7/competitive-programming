#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long>> dp(n+1, vector<long long>(n+1, LONG_LONG_MAX));
    for(int i=1;i<=n;i++) dp[i][i] = 0;
    for(int i=1;i<=m;i++) {
        long long a,b,d;
        cin>>a>>b>>d;
        dp[a][b] = min(dp[a][b], d);
        dp[b][a] = dp[a][b];
    }

    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(dp[i][k] != LONG_LONG_MAX && dp[k][j] != LONG_LONG_MAX) 
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for(int i=1;i<=q;i++) {
        int a,b;
        cin>>a>>b;
        if(dp[a][b] != LONG_LONG_MAX)
            cout<<dp[a][b]<<endl;
        else    
            cout<<-1<<endl;
    }


}