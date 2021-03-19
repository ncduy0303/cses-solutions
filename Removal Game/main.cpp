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
    ll sum = 0;
    for (int &x : a) cin >> x, sum += x;
    ll dp[n][n];
    memset(dp, 0, sizeof dp);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            dp[i][j] = (i == j) ? a[i] : max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
        }
    }
    cout << (sum + dp[0][n - 1]) / 2 << "\n";
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