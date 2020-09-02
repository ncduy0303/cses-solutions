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

// tree query using eulerian ordering and fenwick tree

int n, q, arr[MAX_N], tin[MAX_N], tout[MAX_N], timer;
ll ft[2 * MAX_N];
vi adj[MAX_N];

void update(int x, int v) {
    for (; x <= 2 * n; x += LSOne(x))
        ft[x] += v;
}

ll sum(int x) {
    ll res = 0;
    for (; x; x -= LSOne(x))
        res += ft[x];
    return res;
}

ll rsq(int a, int b) {
    return sum(b) - sum(a - 1);
}

void dfs(int u, int p = 0) {
    tin[u] = ++timer;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    tout[u] = ++timer;
}
 
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        update(tin[i], arr[i]);
        update(tout[i], -arr[i]);
    }
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int s, x; cin >> s >> x;
            update(tin[s], x - arr[s]);
            update(tout[s], -(x - arr[s]));
            arr[s] = x;
        }
        else {
            int s; cin >> s;
            cout << sum(tin[s]) << "\n";
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