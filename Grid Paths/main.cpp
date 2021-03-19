#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

const int n = 7;
 
string s;
int vis[n][n];
 
bool ok(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n && !vis[i][j];
}
 
int backtrack(int i, int j, int pos) {
    if (i == n - 1 && j == 0) return pos == n * n - 1;
    vis[i][j] = true;
    int ans = 0;
    if ((s[pos] == '?' || s[pos] == 'U') && ok(i - 1, j) && !(!ok(i - 2, j) && ok(i - 1, j - 1) && ok(i - 1, j + 1))) ans += backtrack(i - 1, j, pos + 1); 
    if ((s[pos] == '?' || s[pos] == 'D') && ok(i + 1, j) && !(!ok(i + 2, j) && ok(i + 1, j - 1) && ok(i + 1, j + 1))) ans += backtrack(i + 1, j, pos + 1); 
    if ((s[pos] == '?' || s[pos] == 'L') && ok(i, j - 1) && !(!ok(i, j - 2) && ok(i - 1, j - 1) && ok(i + 1, j - 1))) ans += backtrack(i, j - 1, pos + 1); 
    if ((s[pos] == '?' || s[pos] == 'R') && ok(i, j + 1) && !(!ok(i, j + 2) && ok(i - 1, j + 1) && ok(i + 1, j + 1))) ans += backtrack(i, j + 1, pos + 1); 
    vis[i][j] = false;
    return ans;
}

void solve() {
    cin >> s;
    cout << backtrack(0, 0, 0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}