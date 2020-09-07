#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 20;
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

// similar to TSP
int n, m, adj[MAX_N][MAX_N];
ll dp[1 << MAX_N][MAX_N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u][v]++;
    }
    dp[1][0] = 1;
    for (int mask = 2; mask < (1 << n); mask++) {
        if (mask & (1 << (n - 1)) && mask != (1 << n) - 1) continue; // pruning when reaching node n without visiting other nodes
        for (int u = 0; u < n; u++) {
            if (mask & (1 << u)) {
                int new_mask = mask ^ (1 << u);
                for (int v = 0; v < n; v++) {
                    if (new_mask & (1 << v) && adj[v][u]) {
                        dp[mask][u] += adj[v][u] * dp[new_mask][v]; 
                    }
                }
                dp[mask][u] %= MOD; 
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << "\n";
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
