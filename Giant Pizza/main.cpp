#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
const int MAX_N = 1e5 + 5;
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
 
int n, m, scc, comp[2 * MAX_N], visited[2 * MAX_N];
char ans[MAX_N];
vi adj[2][2 * MAX_N], dfn;
 
void dfs(int u, int t) {
    visited[u] = 1;
    if (t == 1) comp[u] = scc;
    for (int v : adj[t][u]) {
        if (!visited[v]) {
            dfs(v, t);
        }
    }
    if (t == 0) dfn.push_back(u);
}
 
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int u1, u2; char c1, c2; cin >> c1 >> u1 >> c2 >> u2;
        u1 *= 2; u2 *= 2; 
        if (c1 == '-') u1 ^= 1;
        if (c2 == '-') u2 ^= 1;
        adj[0][u1^1].push_back(u2);
        adj[0][u2^1].push_back(u1);
        adj[1][u1].push_back(u2^1);
        adj[1][u2].push_back(u1^1);
    }
    for (int i = 1; i <= 2 * m; i++) {
        if (!visited[i]) {
            dfs(i, 0);
        }
    }
    memset(visited, 0, sizeof visited);
    for (int i = 2 * m - 1; i >= 0; i--) {
        if (!visited[dfn[i]]) {
            scc++;
            dfs(dfn[i], 1);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (comp[2 * i] == comp[2 * i + 1]) { // comp[pos] == comp[neg] 
            cout << "IMPOSSIBLE\n";
            return;
        }
        ans[i] = (comp[2 * i] > comp[2 * i + 1]) ? '+' : '-';
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << " ";
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