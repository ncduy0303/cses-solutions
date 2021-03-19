#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n; cin >> n;
    vector<ar<int,3>> a(n);
    for (auto &[r, l, v] : a) cin >> l >> r >> v;
    sort(a.begin(), a.end());
    vector<ll> dp(n);
    dp[0] = a[0][2];
    for (int i = 1; i < n; i++) {
        auto [r, l, v] = a[i];
        int j = lower_bound(a.begin(), a.end(), ar<int,3>{l, -1, -1}) - a.begin() - 1;
        if (j >= 0) {
            dp[i] = max(dp[i - 1], dp[j] + v);
        } else {
            dp[i] = max(dp[i - 1], (ll)v);
        }
    } 
    cout << dp.back() << "\n";
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