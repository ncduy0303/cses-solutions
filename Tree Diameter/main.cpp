#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 2e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, mx, dist[MAX_N];
vector<int> adj[MAX_N];
 
void dfs(int u, int p = 0) {
	for (int v : adj[u]) {
		if (v == p) continue;
		dist[v] = dist[u] + 1;
		if (dist[v] > dist[mx]) mx = v;
		dfs(v, u);
	}
}

void solve() {
    cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	memset(dist, 0, sizeof dist);
	dfs(mx);
	cout << dist[mx] << "\n";
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