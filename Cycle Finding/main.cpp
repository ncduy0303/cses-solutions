#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, m, pre[MAX_N], vis[MAX_N];
vector<ar<int,2>> adj[MAX_N];
vector<ll> dist;

void solve() {
    cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	dist.assign(n + 1, INF);
	dist[1] = 0;
	for (int k = 0; k < n - 1; k++) {
		for (int u = 1; u <= n; u++) {
			for (auto [v, w] : adj[u]) {
				if (dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
					pre[v] = u;
				}
			}
		}
	}
	for (int u = 1; u <= n; u++) {
		for (auto [v, w] : adj[u]) {
			if (dist[v] > dist[u] + w) {
				while (!vis[v]) {
					vis[v] = 1;
					v = pre[v];
				}
				vector<int> ans;
				ans.push_back(v);
				for (int k = pre[v]; k != v; k = pre[k]) ans.push_back(k);
				ans.push_back(v);
				reverse(ans.begin(), ans.end());
				cout << "YES\n";
				for (int x : ans) cout << x << " ";
				cout << "\n";
				return;
			}
		}
	}
	cout << "NO\n";
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