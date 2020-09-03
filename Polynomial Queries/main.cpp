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
 
struct tdata {
    ll len, ap, sum, lz1, lz2;
};
 
int N, Q, arr[MAX_N];
tdata st[4 * MAX_N];

void build(int node, int start, int end) {
    st[node].len = end - start + 1;
    st[node].ap = st[node].len * (start + end) / 2;
    if (start == end) {
        st[node].sum = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    st[node].sum = st[2 * node].sum + st[2 * node + 1].sum;
}
 
void down(int node) { 
    st[2 * node].lz1 += st[node].lz1; st[2 * node + 1].lz1 += st[node].lz1;
    st[2 * node].lz2 += st[node].lz2; st[2 * node + 1].lz2 += st[node].lz2;
    st[2 * node].sum += st[node].lz1 * st[2 * node].ap + st[node].lz2 * st[2 * node].len; 
    st[2 * node + 1].sum += st[node].lz1 * st[2 * node + 1].ap + st[node].lz2 * st[2 * node + 1].len;
    st[node].lz1 = st[node].lz2 = 0;    
}
 
void update(int node, int start, int end, int l, int r) { 
    if (r < start || end < l) return;
    if (l <= start && end <= r) {
        st[node].lz1++;
        st[node].lz2 -= (l - 1);
        st[node].sum += st[node].ap - st[node].len * (l - 1);
        return;
    }
    down(node);
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r);
    update(2 * node + 1, mid + 1, end, l, r);
    st[node].sum = st[2 * node].sum + st[2 * node + 1].sum;
}
 
ll query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return st[node].sum;
    down(node);
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}
 
void solve() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    build(1, 1, N);
    while (Q--) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 1) update(1, 1, N, a, b);
        else cout << query(1, 1, N, a, b) << "\n";
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