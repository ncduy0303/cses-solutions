#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

struct segtree { 
    struct tdata {
        ll mx;
        tdata(): mx(-INF) {}
        tdata(ll val): mx(val) {}
        tdata(tdata l, tdata r): mx(max(l.mx, r.mx)) {}
    };
    int ln(int node) {return 2 * node;}
    int rn(int node) {return 2 * node + 1;}
    int n; vector<tdata> st;
    segtree(int n): n(n), st(4 * n) {}
    segtree(vector<int> &arr) : segtree(arr.size()) {
        build(arr, 1, 0, n - 1);
    }
    void apply(int node, int start, int end, ll val) {
        st[node].mx += val;
    }
    void combine(int node) {
        st[node].mx = max(st[ln(node)].mx, st[rn(node)].mx);
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
    int find(int node, int start, int end, ll v) {
		if (start == end) return st[node].mx >= v ? start : -1;
		int mid = (start + end) / 2;
		return (st[ln(node)].mx >= v) ? find(ln(node), start, mid, v) : find(rn(node), mid + 1, end, v);
	}
	void update(int x, ll v) {update(1, 0, n - 1, x, v);}
	int find(ll v) {return find(1, 0, n - 1, v);}
};

void solve() {
    int n, q; cin >> n >> q;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	segtree st(a);
	while (q--) {
		int v; cin >> v;
		int x = st.find(v);
		if (x != -1) st.update(x, -v); 
		cout << x + 1 << " ";
	}
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