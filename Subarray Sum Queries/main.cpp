#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

struct segtree { 
    struct tdata {
		ll sum, mxps, mxss, mxsas;
		tdata(): sum(), mxps() {}
		tdata(ll val): sum(val), mxps(max(val, 0ll)), mxss(max(val, 0ll)), mxsas(max(val, 0ll)){}
		tdata(tdata l, tdata r): sum(l.sum + r.sum), mxps(max(l.mxps, l.sum + r.mxps)) {}
	};
    int ln(int node) {return 2 * node;}
    int rn(int node) {return 2 * node + 1;}
    int n; vector<tdata> st;
    segtree(int n): n(n), st(4 * n) {}
    segtree(vector<int> &arr) : segtree(arr.size()) {
        build(arr, 1, 0, n - 1);
    }
    void apply(int node, int start, int end, ll val) {
        st[node].sum = val;
		st[node].mxps = max(val, 0ll);
		st[node].mxss = max(val, 0ll);
		st[node].mxsas = max(val, 0ll);
    }
    void combine(int node) {
        st[node].sum = st[ln(node)].sum + st[rn(node)].sum;
		st[node].mxps = max(st[ln(node)].mxps, st[ln(node)].sum + st[rn(node)].mxps);
		st[node].mxss = max(st[rn(node)].mxss, st[rn(node)].sum + st[ln(node)].mxss);
		st[node].mxsas = max({st[ln(node)].mxsas, st[rn(node)].mxsas, st[ln(node)].mxss + st[rn(node)].mxps});
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
    void update(int idx, ll val) {update(1, 0, n - 1, idx, val);}
};

void solve() {
    int n, q; cin >> n >> q;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	segtree st(a);
	while (q--) {
		int x, v; cin >> x >> v; x--;
		st.update(x, v);
		cout << st.st[1].mxsas << "\n";
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