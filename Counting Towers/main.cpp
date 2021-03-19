#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e6 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<ar<ll,2>> dp(MAX_N + 1);

void precompute() {
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i < MAX_N; i++) {
        dp[i][0] = (dp[i - 1][1] + 4 * dp[i - 1][0]) % MOD; 
        dp[i][1] = (dp[i - 1][0] + 2 * dp[i - 1][1]) % MOD;
    }
}

void solve() {
    int n; cin >> n;
    cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    precompute();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}