#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

struct fwtree {
    int n; vector<ll> ft;
    fwtree(int n): n(n), ft(n + 1) {}
    void update(int x, ll v) {
        for (; x <= n; x += x&-x)
            ft[x] += v;
    }
    void update(int l, int r, ll v) {
        update(l, v);
        update(r + 1, -v);
    }
    ll sum(int x) {
        ll res = 0;
        for (; x; x -= x&-x) 
            res += ft[x];
        return res;
    }
};

void solve() {
    int n, q; cin >> n >> q;
	fwtree ft(n);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		ft.update(i, i, x);
	}
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int l, r, v; cin >> l >> r >> v;
			ft.update(l, r, v);
		} else {
			int x; cin >> x;
			cout << ft.sum(x) << "\n";
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