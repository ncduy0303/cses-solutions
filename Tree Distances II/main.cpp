#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 2e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll n, dist[MAX_N], sdist[MAX_N], sz[MAX_N];
vector<int> adj[MAX_N];
 
void dfs1(int u, int p = 0) {
	sz[u] = 1;
	for (int v : adj[u]) {
		if (v == p) continue;
		dist[v] = dist[u] + 1;
		sdist[1] += dist[v];
		dfs1(v, u);
		sz[u] += sz[v];
	}
}
 
void dfs2(int u, int p = 0) {
	if (p) sdist[u] = sdist[p] - sz[u] + (n - sz[u]);
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs2(v, u);
	}
}

void solve() {
    cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1); dfs2(1);
	for (int i = 1; i <= n; i++) cout << sdist[i] << " ";
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