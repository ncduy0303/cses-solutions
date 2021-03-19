#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, m, vis[MAX_N];
vector<int> adj[MAX_N];

void solve() {
    cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		queue<int> q;
		q.push(i);
		vis[i] = 1;
		while (q.size()) {
			int u = q.front(); q.pop();
			for (int v : adj[u]) {
				if (vis[v] == vis[u]) {
					cout << "IMPOSSIBLE\n";
					return;
				}
				if (vis[v] == 3 - vis[u]) continue;
				vis[v] = 3 - vis[u];
				q.push(v);
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << vis[i] << " ";
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