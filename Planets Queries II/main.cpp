#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 2e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

const int MAX_L = 20;
 
int n, q, par[MAX_N][MAX_L], dep[MAX_N], cy[MAX_N];
 
void dfs(int u, int d = 0) {
    cy[u] = --d;
    int v = par[u][0];
    if (!cy[v]) dfs(v, d);
    if (cy[v] < 0) {
        cy[u] = cy[v] - cy[u] + 1;
        dep[u] = 0;
    } else {
        cy[u] = cy[v];
        dep[u] = dep[v] + 1;
    }
}

int ancestor(int u, int k) {
    for (int i = 0; i < MAX_L; i++) 
        if (k & (1 << i)) 
            u = par[u][i];
    return u;
}
 
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    u = ancestor(u, dep[u] - dep[v]);
    if (u == v) return u;
    for (int i = MAX_L - 1; i >= 0; i--)
        if (par[u][i] != par[v][i])
            u = par[u][i], v = par[v][i];
    return par[u][0];
}

void solve() {
    cin >> n >> q;
	for (int u = 1; u <= n; u++) cin >> par[u][0];
	for (int i = 1; i < MAX_L; i++) {
		for (int u = 1; u <= n; u++) par[u][i] = par[par[u][i - 1]][i - 1];
	}
	for (int u = 1; u <= n; u++) {
		if (cy[u]) continue;
		dfs(u);
	}
	while (q--) {
		int u, v; cin >> u >> v;
		if (dep[u] >= dep[v] && ancestor(u, dep[u] - dep[v]) == v) {
			cout << dep[u] - dep[v] << "\n";
		} else if (dep[u] + cy[u] >= dep[v] && ancestor(u, dep[u] + cy[u] - dep[v]) == v) {
			cout << dep[u] + cy[u] - dep[v] << "\n";
		} else {
			cout << -1 << "\n";
		}
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