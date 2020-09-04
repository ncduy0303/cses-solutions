#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
const int MAX_N = 2e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;
const double EPS = 1e-9;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
 
#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)
 
// Persistent Segment Tree
 
typedef struct ptr {
    ptr *l, *r;
    ll sum;
} *tdata;
 
int N, Q, arr[MAX_N], nVer;
tdata ver[MAX_N];
 
tdata init() {
    tdata res = new ptr();
    res->l = res->r = NULL;
    res->sum = 0;
    return res;
}
 
void build(tdata &node, int start, int end) {
    node = init();
    if (start == end) {
        node->sum = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(node->l, start, mid);
    build(node->r, mid + 1, end);
    node->sum = node->l->sum + node->r->sum;
}
 
void update(tdata &node, tdata pre_node, int start, int end, int idx, int val) {
    node = init();
    if (start == end) {
        node->sum += val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) {
        node->r = pre_node->r;
        update(node->l, pre_node->l, start, mid, idx, val);
    }
    else {
        node->l = pre_node->l;
        update(node->r, pre_node->r, mid + 1, end, idx, val);
    }
    node->sum = node->l->sum + node->r->sum;
}
 
ll query(tdata node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return node->sum;
    int mid = (start + end) / 2;
    return query(node->l, start, mid, l, r) + query(node->r, mid + 1, end, l, r);
}
 
void solve() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    build(ver[++nVer], 1, N);
    while (Q--) {
        int t, k; cin >> t >> k;
        if (t == 1) {
            int a, x; cin >> a >> x;
            tdata node = init();
            update(node, ver[k], 1, N, a, x);
            ver[k] = node;
        }
        else if (t == 2) {
            int a, b; cin >> a >> b;
            cout << query(ver[k], 1, N, a, b) << "\n";
        }
        else {
            ver[++nVer] = ver[k];
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    int tc; tc = 1;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t  << ": ";
        solve();
    }
}