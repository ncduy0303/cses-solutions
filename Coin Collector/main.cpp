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

int n, m, scc, arr[MAX_N], comp[MAX_N], visited[MAX_N];
ll new_arr[MAX_N], dp[MAX_N];
vi adj[2][MAX_N], new_adj[MAX_N], dfn;
 
void dfs(int u, int t) {
    visited[u] = 1;
    if (t == 1) {
        comp[u] = scc;
        new_arr[scc] += arr[u];
    }
    for (int v : adj[t][u]) {
        if (!visited[v]) {
            dfs(v, t);
        }
    }
    if (t == 0) dfn.push_back(u);
}

ll dfs2(int u) {
    ll res = 0;
    for (int v : new_adj[u]) {
        if (!dp[v]) dfs2(v);
        res = max(res, dp[v]);
    }
    return dp[u] = res + new_arr[u];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[0][u].push_back(v);
        adj[1][v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, 0);
        }
    }
    memset(visited, 0, sizeof visited);
    for (int i = n - 1; i >= 0; i--) {
        if (!visited[dfn[i]]) {
            scc++;
            dfs(dfn[i], 1);
        }
    }

    for (int u = 1; u <= n; u++) 
        for (int v : adj[0][u])
            if (comp[u] != comp[v])
                new_adj[comp[u]].push_back(comp[v]);
    ll ans = 0;
    for (int i = 1; i <= scc; i++)
        ans = max(ans, dfs2(i));
    cout << ans << "\n";
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
