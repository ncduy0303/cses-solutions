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
    ll sum(int x) {
        ll res = 0;
        for (; x; x -= x&-x) 
            res += ft[x];
        return res;
    }
    ll query(int l, int r) {return sum(r) - sum(l - 1);}
};

void solve() {
    int n, q; cin >> n >> q;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<ar<int,2>> queries[n + 1];
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		queries[r].push_back({l, i});
	}
	fwtree ft(n);
	map<int,int> mp;
	vector<int> ans(q);
	for (int r = 1; r <= n; r++) {
		if (mp[a[r]]) ft.update(mp[a[r]], -1); 
		mp[a[r]] = r;
		ft.update(mp[a[r]], 1);
		for (auto [l, i] : queries[r]) {
			ans[i] = ft.query(l, r);
		}
	}
	for (int x : ans) cout << x << "\n";
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