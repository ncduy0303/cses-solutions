#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

struct segtree { 
    struct tdata {
		ll sum, lzadd, lzset;
		tdata() : sum(), lzadd(), lzset(INF) {}
		tdata(ll val): sum(val), lzadd(), lzset(INF) {}
		tdata(tdata l, tdata r) : sum(l.sum + r.sum), lzadd(), lzset(INF) {}
	};
    int ln(int node) {return 2 * node;}
    int rn(int node) {return 2 * node + 1;}
    int n; vector<tdata> st;
    segtree(int n): n(n), st(4 * n) {}
    segtree(vector<int> &arr) : segtree(arr.size()) {
        build(arr, 1, 0, n - 1);
    }
    void apply_add(int node, int start, int end, ll val) {
		if (val == 0) return;
		st[node].sum += val * (end - start + 1);
		st[node].lzadd += val;
	}
	void apply_set(int node, int start, int end, ll val) {
		if (val == INF) return;
		st[node].sum = val * (end - start + 1);
		st[node].lzadd = 0;
		st[node].lzset = val;
	}
    void combine(int node) {
        st[node].sum = st[ln(node)].sum + st[rn(node)].sum;
    }
    void propagate(int node, int start, int end) {
		if (start == end) return;
		int mid = (start + end) / 2;
		apply_set(ln(node), start, mid, st[node].lzset);
        apply_set(rn(node), mid + 1, end, st[node].lzset);
        apply_add(ln(node), start, mid, st[node].lzadd);
        apply_add(rn(node), mid + 1, end, st[node].lzadd);
		st[node].lzadd = 0;
		st[node].lzset = INF;
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
    void update_add(int node, int start, int end, int l, int r, ll val) {
		propagate(node, start, end);
		if (r < start || end < l) return;
		if (l <= start && end <= r) {
			apply_add(node, start, end, val);
			return;
		}
		int mid = (start + end) / 2;
		update_add(ln(node), start, mid, l, r, val);
		update_add(rn(node), mid + 1, end, l, r, val);
		combine(node);
	}
	void update_set(int node, int start, int end, int l, int r, ll val) {
		propagate(node, start, end);
		if (r < start || end < l) return;
		if (l <= start && end <= r) {
			apply_set(node, start, end, val);
			return;
		}
		int mid = (start + end) / 2;
		update_set(ln(node), start, mid, l, r, val);
		update_set(rn(node), mid + 1, end, l, r, val);
		combine(node);
	}
	tdata query(int node, int start, int end, int l, int r) {
		propagate(node, start, end);
		if (r < start || end < l) return tdata();
		if (l <= start && end <= r) return st[node];
		int mid = (start + end) / 2;
		return tdata(query(ln(node), start, mid, l, r), query(rn(node), mid + 1, end, l, r));
	}
	void update_add(int l, int r, ll val) {update_add(1, 0, n - 1, l, r, val);}
	void update_set(int l, int r, ll val) {update_set(1, 0, n - 1, l, r, val);}
	tdata query(int l, int r) {return query(1, 0, n - 1, l, r);}
};

void solve() {
    int n, q; cin >> n >> q;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	segtree st(a);
	while (q--) {
		int t, l, r; cin >> t >> l >> r; l--; r--;
		if (t == 1) {
			int v; cin >> v;
			st.update_add(l, r, v);
		} else if (t == 2) {
			int v; cin >> v;
			st.update_set(l, r, v);
		} else {
			cout << st.query(l, r).sum << "\n";
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