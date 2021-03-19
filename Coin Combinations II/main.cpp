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
    vector<int> dp(m + 1);
    dp[0] = 1;
    for (int x : a) {
        for (int i = 1; i <= m; i++) {
            if (i - x >= 0) {
                dp[i] = (dp[i] + dp[i - x]) % MOD;
            }
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