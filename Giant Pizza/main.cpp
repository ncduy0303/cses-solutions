#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 2e5 + 2;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, m, scc, vis[2 * MAX_N], head[2 * MAX_N];
vector<int> adj[2 * MAX_N], adj_T[2 * MAX_N], comp[2 * MAX_N], topo;
 
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
    cin >> m >> n;
	for (int i = 0; i < m; i++) {
		int u1, u2; char c1, c2; cin >> c1 >> u1 >> c2 >> u2; 
		u1 *= 2; u2 *= 2;
		if (c1 == '-') u1 ^= 1;
		if (c2 == '-') u2 ^= 1;
		adj[u1].push_back(u2 ^ 1);
		adj[u2].push_back(u1 ^ 1);
		adj_T[u1 ^ 1].push_back(u2);
		adj_T[u2 ^ 1].push_back(u1);
	}
	for (int u = 1; u <= 2 * n; u++) {
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
	vector<char> ans(n);
	for (int i = 1; i <= n; i++) {
		int u = 2 * i;
		if (head[u] == head[u ^ 1]) {
			cout << "IMPOSSIBLE\n";
			return;
		} else {
			ans[i - 1] = (head[u] < head[u ^ 1]) ? '+' : '-';
		}
	}
	for (char c : ans) cout << c << " ";
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