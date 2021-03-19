#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, m, scc, vis[MAX_N], head[MAX_N];
vector<int> adj[MAX_N], adj_T[MAX_N], comp[MAX_N], topo;
 
void dfs1(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (vis[v]) continue;
        dfs1(v);
    }
    topo.push_back(u);
}
 
void dfs2(int u) {
    vis[u] = true;
    comp[scc].push_back(u);
    head[u] = scc;
    for (int v : adj_T[u]) {
        if (vis[v]) continue;
        dfs2(v);
    }
}

void kosaraju() {
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs1(i);
    }
    memset(vis, 0, sizeof vis);
    reverse(topo.begin(), topo.end());
    for (int i : topo) {
        if (vis[i]) continue;
        dfs2(i);
        scc++;
    }
}

void solve() {
    cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj_T[v].push_back(u);
	}
	for (int u = 1; u <= n; u++) {
		if (vis[u]) continue;
		dfs1(u);
	}
	memset(vis, 0, sizeof vis);
	reverse(topo.begin(), topo.end());
	for (int u : topo) {
		if (vis[u]) continue;
		scc++;
		dfs2(u);
	}
	if (scc == 1) cout << "YES\n";
	else {
		cout << "NO\n";
		memset(vis, 0, sizeof vis);
		dfs1(comp[1][0]);
		if (vis[comp[2][0]]) cout << comp[2][0] << " " << comp[1][0] << "\n";
		else cout << comp[1][0] << " " << comp[2][0] << "\n";
	}
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