#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, m, vis[MAX_N];
vector<int> adj[MAX_N], topo;
 
void dfs(int u) {
	vis[u] = 1;
	for (int v : adj[u]) {
		if (vis[v] == 2) continue;
		if (vis[v] == 1) {
			cout << "IMPOSSIBLE\n";
			exit(0);
		}
		dfs(v);
	}
	topo.push_back(u);
	vis[u] = 2;
}

void solve() {
    cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		dfs(i);
	}
	reverse(topo.begin(), topo.end());
	for (int x : topo) cout << x << " ";
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