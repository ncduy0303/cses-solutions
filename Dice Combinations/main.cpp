#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n; cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i + j <= n) {
                dp[i + j] = (dp[i + j] + dp[i]) % MOD;
            }
        }
    }
    cout << dp[n];
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