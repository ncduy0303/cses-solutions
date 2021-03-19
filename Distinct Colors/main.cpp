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

int n, timer, tin[MAX_N], tout[MAX_N];
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
    cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	vector<int> arr(n + 1);
	for (int u = 1; u <= n; u++) arr[tin[u]] = a[u];	
	vector<ar<int,2>> queries[n + 1];
	for (int i = 1; i <= n; i++) {
		int l = tin[i], r = tout[i];
		queries[r].push_back({l, i});
	}
	fwtree ft(n);
	map<int,int> mp;
	vector<int> ans(n + 1);
	for (int r = 1; r <= n; r++) {
		if (mp[arr[r]]) ft.update(mp[arr[r]], -1); 
		mp[arr[r]] = r;
		ft.update(mp[arr[r]], 1);
		for (auto [l, i] : queries[r]) {
			ans[i] = ft.query(l, r);
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
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