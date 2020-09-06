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

int n, m, visited[MAX_N], par[MAX_N];
vi adj[MAX_N], topo;

void dfs(int u) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v);
        else if (visited[v] == 1) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
    }
    visited[u] = 2;
    topo.push_back(u);
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(i);
    reverse(topo.begin(), topo.end());
    
    vi dp(n + 1, 0); 
    dp[1] = 1; par[1] = -1;
    for (int u : topo) {
        if (u == n) break;
        if (dp[u]) {
            for (int v : adj[u]) {
                if (dp[u] + 1 > dp[v]) {
                    dp[v] = dp[u] + 1;
                    par[v] = u;
                } 
            }
        }
    }
    if (!dp[n]) cout << "IMPOSSIBLE\n";
    else {
        vi ans;
        for (int i = n; i != -1; i = par[i]) ans.push_back(i);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (int x : ans) cout << x << " ";
        cout << "\n";
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
