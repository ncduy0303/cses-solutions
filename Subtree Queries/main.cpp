#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 2e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

struct fwtree {
    int n; vector<ll> ft;
    fwtree(int n): n(n), ft(n + 1) {}
    void update(int x, ll v) {
        for (; x <= n; x += x&-x)
            ft[x] += v;
    }
    ll sum(int x) {
        ll res = 0;
        for (; x; x -= x&-x) 
            res += ft[x];
        return res;
    }
    ll query(int l, int r) {return sum(r) - sum(l - 1);}
};

int n, q, timer, tin[MAX_N], tout[MAX_N];
vector<int> adj[MAX_N];
 
void dfs(int u, int p = 0) {
	tin[u] = ++timer;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
	tout[u] = timer;
}

void solve() {
    cin >> n >> q;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	fwtree ft(n);
	for (int u = 1; u <= n; u++) ft.update(tin[u], a[u]);
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int u, x; cin >> u >> x;
			ft.update(tin[u], x - a[u]);
			a[u] = x;
		} else {
			int u; cin >> u;
			cout << ft.query(tin[u], tout[u]) << "\n";
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