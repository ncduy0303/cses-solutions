#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n, l, r; cin >> n >> l >> r;
	double dp[n + 1][6 * n + 1] = {};
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 6 * n; j++) {
			for (int k = 1; k <= 6 && j + k <= 6 * n; k++) {
				dp[i + 1][j + k] += dp[i][j] / 6;
			}
		}
	}
	double ans = 0;
	for (int i = l; i <= r; i++) ans += dp[n][i];
	cout << fixed << setprecision(6) << ans << "\n";
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