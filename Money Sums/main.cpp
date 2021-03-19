#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<bool> dp(MAX_N + 1);
    dp[0] = true;
    for (int x : a) {
        for (int j = MAX_N - 1; j >= x; j--) {
            dp[j] = dp[j] | dp[j - x];
        }
    }
    int ans = 0;
    for (int i = 1; i < MAX_N; i++) ans += dp[i];
    cout << ans << "\n";
    for (int i = 1; i < MAX_N; i++) {
        if (dp[i]) cout << i << " ";
    }
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