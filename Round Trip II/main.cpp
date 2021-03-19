#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, m, vis[MAX_N], pre[MAX_N];
vector<int> adj[MAX_N];
 
void dfs(int u, int p = 0) {
	vis[u] = 1;
	pre[u] = p;
	for (int v : adj[u]) {
		if (vis[v] == 0) {
			dfs(v, u);
		} else if (vis[v] == 1) {
			vector<int> ans;
			ans.push_back(v);
			for (int k = u; k != v; k = pre[k]) ans.push_back(k);
			ans.push_back(v);
			reverse(ans.begin(), ans.end());
			cout << ans.size() << "\n";
			for (int x : ans) cout << x << " ";
			cout << "\n";
			exit(0);
		}
	}
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
	cout << "IMPOSSIBLE\n";
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