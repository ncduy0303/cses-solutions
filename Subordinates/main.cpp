#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 2e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, sz[MAX_N];
vector<int> adj[MAX_N];
 
void dfs(int u) {
	for (int v : adj[u]) {
		dfs(v);
		sz[u] += sz[v] + 1;
	}
}

void solve() {
    cin >> n;
	for (int v = 2; v <= n; v++) {
		int u; cin >> u;
		adj[u].push_back(v);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) cout << sz[i] << " ";
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