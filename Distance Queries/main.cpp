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
 
int n, q, dp[MAX_N][MAX_L], dep[MAX_N];
vi adj[MAX_N];
 
void dfs(int u, int p = 0) {
    dp[u][0] = p;
    dep[u] = dep[p] + 1;
    for (int i = 1; i < MAX_L; i++)
        dp[u][i] = dp[dp[u][i - 1]][i - 1];
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}
 
int ancestor(int u, int k) {
    for (int i = 0; i < MAX_L && u; i++)
        if (k & (1 << i))
            u = dp[u][i];
    return u;
}
 
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    u = ancestor(u, dep[u] - dep[v]);
    if (u == v) return u;
    for (int i = MAX_L - 1; i >= 0; i--)
        if (dp[u][i] != dp[v][i])
            u = dp[u][i], v = dp[v][i];
    return dp[u][0];
}
 
void solve() {
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    while (q--) {
        int a, b; cin >> a >> b;
        cout << dep[a] + dep[b] - 2 * dep[lca(a, b)] << "\n";
    }
    cout << "\n";
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