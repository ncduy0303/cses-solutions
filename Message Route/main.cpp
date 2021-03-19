#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, m, dist[MAX_N], pre[MAX_N];
vector<int> adj[MAX_N];

void solve() {
    cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int> q;
	q.push(1);
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 1;
	pre[1] = 0;
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (dist[v] > dist[u] + 1) {
				dist[v] = dist[u] + 1;
				pre[v] = u;
				q.push(v);
			}
		}
	}
	if (dist[n] < INF) {
		cout << dist[n] << "\n";
		vector<int> ans;
		for (int u = n; u; u = pre[u]) ans.push_back(u);
		reverse(ans.begin(), ans.end());
		for (int x : ans) cout << x << " ";
		cout << "\n";
	} else {
		cout << "IMPOSSIBLE\n";
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