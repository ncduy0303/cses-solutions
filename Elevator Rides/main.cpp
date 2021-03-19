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
    vector<ar<int,2>> dp(1 << n, {n ,0});
    dp[0] = {1, 0};
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) {
                auto nxt = dp[mask ^ (1 << i)];
                if (nxt[1] + a[i] > m) nxt = {nxt[0] + 1, a[i]};
                else nxt = {nxt[0], a[i] + nxt[1]};
                dp[mask] = min(dp[mask], nxt);
            }
        }
    }
    cout << dp.back()[0] << "\n";
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