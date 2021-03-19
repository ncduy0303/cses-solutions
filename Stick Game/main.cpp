#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(k);
    for (int &x : a) cin >> x;
    vector<bool> dp(n + 1);
    dp[0] = false;
    for (int i = 0; i <= n; i++) {
        for (int x : a) {
            if (i + x > n) continue;
            dp[i + x] = dp[i + x] | !dp[i];
        }
    }
    for (int i = 1; i <= n; i++) cout << (dp[i] ? "W" : "L");
    cout << "\n";
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