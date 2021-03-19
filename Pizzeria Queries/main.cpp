#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

struct segtree { 
    struct tdata {
        ll mn;
        tdata(): mn(INF) {}
        tdata(ll val): mn(val) {}
        tdata(tdata l, tdata r): mn(min(l.mn, r.mn)) {}
    };
    int ln(int node) {return 2 * node;}
    int rn(int node) {return 2 * node + 1;}
    int n; vector<tdata> st;
    segtree(int n): n(n), st(4 * n) {}
    segtree(vector<int> &arr) : segtree(arr.size()) {
        build(arr, 1, 0, n - 1);
    }
    void apply(int node, int start, int end, ll val) {
        st[node].mn = val;
    }
    void combine(int node) {
        st[node].mn = min(st[ln(node)].mn, st[rn(node)].mn);
    }
    void build(vector<int> &arr, int node, int start, int end) {
        if (start == end) {
            st[node] = tdata(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(arr, ln(node), start, mid);
        build(arr, rn(node), mid + 1, end);
        combine(node);
    }
    void update(int node, int start, int end, int idx, ll val) {
        if (start == end) {
            apply(node, start, end, val);
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(ln(node), start, mid, idx, val);
        else update(rn(node), mid + 1, end, idx, val);
        combine(node);
    }
    tdata query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return tdata();
        if (l <= start && end <= r) return st[node];
        int mid = (start + end) / 2;
        return tdata(query(ln(node), start, mid, l, r), query(rn(node), mid + 1, end, l, r));
    }
    void update(int idx, ll val) {update(1, 0, n - 1, idx, val);}
    tdata query(int l, int r) {return query(1, 0, n - 1, l, r);}
};

void solve() {
    int n, q; cin >> n >> q;
	vector<int> a1(n), a2(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a1[i] = x - i;
		a2[i] = x + i;
	}
	segtree st1(a1), st2(a2);
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int x, v; cin >> x >> v; x--;
			st1.update(x, v - x);
			st2.update(x, v + x);
		} else {
			int x; cin >> x; x--;
			cout << min(st1.query(0, x).mn + x, st2.query(x, n - 1).mn - x) << "\n";
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