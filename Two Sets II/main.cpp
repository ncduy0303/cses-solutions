#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n; cin >> n;
    if (n * (n + 1) % 4) {
        cout << 0 << "\n";
        return;
    }
    int m = n * (n + 1) / 4;
    vector<int> dp(m + 1);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = m; j >= i; j--) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }
    cout << dp[m] << "\n";
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