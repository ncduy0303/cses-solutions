#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

struct segtree { 
    struct tdata {
		ll sum, lzadd, lzstep;
		tdata() : sum(), lzadd(), lzstep() {}
		tdata(ll val): sum(val), lzadd(), lzstep() {}
		tdata(tdata l, tdata r) : sum(l.sum + r.sum), lzadd(), lzstep() {}
	};
    int ln(int node) {return 2 * node;}
    int rn(int node) {return 2 * node + 1;}
    int n; vector<tdata> st;
    segtree(int n): n(n), st(4 * n) {}
    segtree(vector<int> &arr) : segtree(arr.size()) {
        build(arr, 1, 0, n - 1);
    }
    void apply(int node, int start, int end, ll add, ll step) {
		ll len = end - start + 1;
		st[node].sum += add * len + step * len * (len + 1) / 2;
		st[node].lzadd += add;
		st[node].lzstep += step;
	}
	void combine(int node) {
        st[node].sum = st[ln(node)].sum + st[rn(node)].sum;
    }
    void propagate(int node, int start, int end) {
		if (start == end) return;
		int mid = (start + end) / 2;
		apply(ln(node), start, mid, st[node].lzadd, st[node].lzstep);
        apply(rn(node), mid + 1, end, st[node].lzadd + st[node].lzstep * (mid + 1 - start), st[node].lzstep);
        st[node].lzadd = 0;
        st[node].lzstep = 0;
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
    void update(int node, int start, int end, int l, int r) {
		propagate(node, start, end);
		if (r < start || end < l) return;
		if (l <= start && end <= r) {
			apply(node, start, end, start - l, 1);
			return;
		}
		int mid = (start + end) / 2;
		update(ln(node), start, mid, l, r);
		update(rn(node), mid + 1, end, l, r);
		combine(node);
	}
    tdata query(int node, int start, int end, int l, int r) {
        propagate(node, start, end);
        if (r < start || end < l) return tdata();
        if (l <= start && end <= r) return st[node];
        int mid = (start + end) / 2;
        return tdata(query(ln(node), start, mid, l, r), query(rn(node), mid + 1, end, l, r));
    }
    void update(int l, int r) {update(1, 0, n - 1, l, r);}
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
			st.update(l, r);
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