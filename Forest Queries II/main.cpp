#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

struct fwtree {
    int n; vector<vector<ll>> ft;
    fwtree(int n): n(n), ft(n + 1, vector<ll>(n + 1)) {}
    void update(int x, int y, ll v) {
        for (int tx = x; tx <= n; tx += tx&-tx)
            for (int ty = y; ty <= n; ty += ty&-ty)
                ft[tx][ty] += v;
    }
    ll sum(int x, int y) {
        ll res = 0;
        for (int tx = x; tx; tx -= tx&-tx) 
            for (int ty = y; ty; ty -= ty&-ty)
                res += ft[tx][ty];
        return res;
    }
    ll query(int x1, int y1, int x2, int y2) {return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);}
};

void solve() {
    int n, q; cin >> n >> q;
	fwtree ft(n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c; cin >> c;
			ft.update(i, j, c == '*');
		}
	}
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int x, y; cin >> x >> y;
			ft.update(x, y, ft.query(x, y, x, y) ? -1 : 1);
		} else {
			int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
			cout << ft.query(x1, y1, x2, y2) << "\n";
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