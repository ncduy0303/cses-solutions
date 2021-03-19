#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, m, vis[MAX_N];
vector<int> adj[MAX_N];
 
void dfs(int u) {
	vis[u] = 1;
	for (int v : adj[u]) {
		if (vis[v]) continue;
		dfs(v);
	}
}

void solve() {
    cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> ans;
	for (int u = 1; u <= n; u++) {
		if (vis[u]) continue;
		dfs(u);
		ans.push_back(u);
	}
	cout << ans.size() - 1 << "\n";
	for (int i = 1; i < ans.size(); i++) cout << ans[i - 1] << " " << ans[i] << "\n";
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