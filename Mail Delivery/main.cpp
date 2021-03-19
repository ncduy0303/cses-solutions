#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

const int MAX_M = 2e5 + 1;
 
int n, m, vis[MAX_M];
vector<ar<int,2>> adj[MAX_N];
vector<int> ans;
 
void dfs(int u) {
	while (adj[u].size()) {
		auto [v, i] = adj[u].back(); adj[u].pop_back();
		if (vis[i]) continue;
		vis[i] = 1;
		dfs(v);
	}
	ans.push_back(u);
}

void solve() {
    cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() % 2) {
			cout << "IMPOSSIBLE\n";
			return;
		}
	}
	dfs(1);
	if (ans.size() != m + 1) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	for (int x : ans) cout << x << " ";
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