#include <bits/stdc++.h>
using namespace std;

map<char, char> inv = {
    {'N', 'S'}, 
    {'S', 'N'},
    {'E', 'W'}, 
    {'W', 'E'}
};

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int x = 0, y = 0;
    for(char c : s) {
        if(c == 'N') y++;
        if(c == 'S') y--;
        if(c == 'E') x++;
        if(c == 'W') x--;
    }
    
    if(x % 2 == 1 || y % 2 == 1) {
        cout << "NO\n";
        return;
    }
    
    string ans(n, 'R');  // Initialize string of length n with all 'R'
    
    if(x == 0 && y == 0) {
        if(n == 2) {
            cout << "NO\n";
            return;
        }
        // Find the opposite direction of first move
        char opposite = inv[s[0]];
        ans[0] = 'H';
        // Find first occurrence of opposite direction
        size_t pos = s.find(opposite);
        ans[pos] = 'H';
    } else {
        for(int i = 0; i < n; i++) {
            if(s[i] == 'N' && y > 0) {
                y -= 2;
                ans[i] = 'H';
            }
            if(s[i] == 'S' && y < 0) {
                y += 2;
                ans[i] = 'H';
            }
            if(s[i] == 'E' && x > 0) {
                x -= 2;
                ans[i] = 'H';
            }
            if(s[i] == 'W' && x < 0) {
                x += 2;
                ans[i] = 'H';
            }
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}