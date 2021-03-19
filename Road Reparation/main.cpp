#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

struct DSU {
    int num; vector<int> p, sz;
    DSU(int n) {
        num = n;
        p.resize(n); for (int i = 0; i < n; i++) p[i] = i;
        sz.assign(n, 1);
    }
    int find(int u) {return u == p[u] ? u : p[u] = find(p[u]);}
    bool same(int u, int v) {return find(u) == find(v);}
    void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (sz[u] > sz[v]) swap(u, v);
        sz[v] += sz[u];
        p[u] = v;
        num--;
    }
};

void solve() {
    int n, m; cin >> n >> m;
	vector<ar<int,3>> el(m);
	for (auto &[w, u, v] : el) cin >> u >> v >> w;
	sort(el.begin(), el.end());
	DSU uf(n);
	ll ans = 0;
	for (auto [w, u, v] : el) {
		if (uf.same(u, v)) continue;
		uf.merge(u, v);
		ans += w;
	}
	if (uf.num != 1) cout << "IMPOSSIBLE\n";
	else cout << ans << "\n";
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