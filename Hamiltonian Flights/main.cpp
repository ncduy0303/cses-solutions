#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n, m; cin >> n >> m;
	vector<int> adj[n];
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--; v--;
		adj[u].push_back(v);
	}
	ll dp[n][1 << n] = {};
	dp[0][1] = 1;
	for (int mask = 1; mask < (1 << n); mask++) {
		if (mask >> (n - 1) & 1 && mask != (1 << n) - 1) continue;
		for (int u = 0; u < n; u++) {
			if (mask >> u & 1) {
				for (int v : adj[u]) {
					if (mask >> v & 1) continue;
					int nmask = mask ^ (1 << v);
					dp[v][nmask] = (dp[v][nmask] + dp[u][mask]) % MOD;
				}
			}
		}
	}
	cout << dp[n - 1][(1 << n) - 1] << "\n";
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