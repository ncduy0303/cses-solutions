#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

struct segtree { 
    struct tdata {
        tdata *ln = NULL, *rn = NULL;
        ll sum, setval;
        tdata(): sum(), setval(INF) {}
        tdata(ll val): sum(val), setval(INF) {}
        tdata(tdata *ln, tdata *rn, ll val): ln(ln), rn(rn), sum(val), setval(INF) {}
        tdata(tdata l, tdata r): sum(l.sum + r.sum), setval(INF) {}
        void init() {
            if (ln == NULL) {
                ln = new tdata(), rn = new tdata();
            }
        }
    };
    int n, ver; vector<tdata*> st;
    segtree(int n, int q): n(n), ver(), st(q) {
        st[0] = new tdata();
    }
    segtree(vector<int> &arr, int q) : segtree(arr.size(), q) {
        build(arr, st[0], 0, n - 1);
    }
    void apply(tdata *node, int start, int end, ll val) {
        node->sum = val * (end - start + 1);
        node->setval = val;
    }
    void combine(tdata *node) {
        node->sum = node->ln->sum + node->rn->sum;
    }
    void propagate(tdata *node, int start, int end) {
        if (start == end || node->setval == INF) return;
        node->init();
        int mid = (start + end) / 2;
        apply(node->ln, start, mid, node->setval);
        apply(node->rn, mid + 1, end, node->setval);
        node->setval = INF;
    }
    void build(vector<int> &arr, tdata *node, int start, int end) {
        if (start == end) {
            *node = tdata(arr[start]);
            return;
        }
        node->init();
        int mid = (start + end) / 2;
        build(arr, node->ln, start, mid);
        build(arr, node->rn, mid + 1, end);
        combine(node);
    }
    void update(tdata *node, int start, int end, int idx, ll val) {
        propagate(node, start, end);
        if (start == end) {
            apply(node, start, end, val);
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) {
            node->ln = new tdata(node->ln->ln, node->ln->rn, node->ln->sum);
            update(node->ln, start, mid, idx, val);
        }
        else {
            node->rn = new tdata(node->rn->ln, node->rn->rn, node->rn->sum);
            update(node->rn, mid + 1, end, idx, val);
        }
        combine(node);
    }
    void update(tdata *node, int start, int end, int l, int r, ll val) {
        propagate(node, start, end);
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            apply(node, start, end, val);
            return;
        }
        int mid = (start + end) / 2;
        node->ln = new tdata(node->ln->ln, node->ln->rn, node->ln->sum);
        node->rn = new tdata(node->rn->ln, node->rn->rn, node->rn->sum);
        update(node->ln, start, mid, l, r, val);
        update(node->rn, mid + 1, end, l, r, val);
        combine(node);
    }
    tdata query(tdata *node, int start, int end, int l, int r) {
        propagate(node, start, end);
        if (r < start || end < l) return tdata();
        if (l <= start && end <= r) return *node;
        int mid = (start + end) / 2;
        return tdata(query(node->ln, start, mid, l, r), query(node->rn, mid + 1, end, l, r));
    }
    void update(int k, int idx, ll val) {update(st[k], 0, n - 1, idx, val);}
    void update(int k, int l, int r, ll val) {update(st[k], 0, n - 1, l, r, val);}
    tdata query(int k, int l, int r) {return query(st[k], 0, n - 1, l, r);}
    void copy(int k) {st[++ver] = new tdata(st[k]->ln, st[k]->rn, st[k]->sum);}
};

void solve() {
    int n, q; cin >> n >> q;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	segtree st(a, q);
	while (q--) {
		int t, k; cin >> t >> k; k--;
		if (t == 1) {
			int x, v; cin >> x >> v; x--;
			st.update(k, x, v);
		} else if (t == 2) {
			int l, r; cin >> l >> r; l--; r--;
			cout << st.query(k, l, r).sum << "\n";
		} else {
			st.copy(k);
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