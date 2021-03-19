#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n, m; cin >> n >> m;
    ll dp[1 << n][3] = {};
    dp[0][1] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int mask = 0; mask < (1 << n); mask++) {
                dp[mask][2] = dp[mask ^ (1 << j)][1];
                if (j && !(mask & (1 << j)) && !(mask & (1 << (j - 1)))) dp[mask][2] += dp[mask][0];
                if (dp[mask][2] >= MOD) dp[mask][2] -= MOD;
            }
            for (int mask = 0; mask < (1 << n); mask++) {
                dp[mask][0] = dp[mask][1];
                dp[mask][1] = dp[mask][2];
            }
        }
    }
    cout << dp[0][1] << "\n";
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