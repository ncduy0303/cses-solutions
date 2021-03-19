#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int dp[n][m + 1];
    memset(dp, 0, sizeof dp);
    if (a[0] == 0) {
        for (int i = 1; i <= m; i++) dp[0][i] = 1;
    } else {
        dp[0][a[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                if (j < m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        } else {
            int j = a[i];
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if (j > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            if (j < m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) ans = (ans + dp[n - 1][i]) % MOD;
    cout << ans << "\n";
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