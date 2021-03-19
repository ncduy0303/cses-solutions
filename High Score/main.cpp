#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 2.5e3 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int n, m, vis[MAX_N];
vector<ar<int,2>> adj[MAX_N];
vector<ll> dist;

void dfs(int u) {
	vis[u] = 1;
	for (auto [v, w] : adj[u]) {
		if (vis[v]) continue;
		dfs(v);
	}
}

void solve() {
    cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	dist.assign(n + 1, -INF);
	dist[1] = 0;
	for (int k = 0; k < n - 1; k++) {
		for (int u = 1; u <= n; u++) {
			for (auto [v, w] : adj[u]) {
				dist[v] = max(dist[v], dist[u] + w);
			}
		}
	}
	for (int u = 1; u <= n; u++) {
		for (auto [v, w] : adj[u]) {
			if (dist[v] < dist[u] + w) {
				memset(vis, 0, sizeof vis);
				dfs(1);
				if (!vis[v]) continue;
				memset(vis, 0, sizeof vis);
				dfs(v);
				if (!vis[n]) continue;
				cout << -1 << "\n";
				return;
			}
		}
	}
	cout << dist[n] << "\n";
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