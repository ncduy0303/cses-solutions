#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 3e3 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e15 + 7;
const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)

int n, m, par[MAX_N];
vii adj[MAX_N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vi dist(n + 1, INF);
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int u = 1; u <= n; u++) {
            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    par[v] = u;
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
    int cycle = 0;
    for (int u = 1; u <= n; u++) {
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                cycle = v; 
                break;
            }
        }
    }
    if (!cycle) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 0; i < n; i++) cycle = par[cycle];
        vi ans = {cycle};
        for (int i = par[cycle]; i != cycle; i = par[i]) ans.push_back(i);
        ans.push_back(cycle);
        reverse(ans.begin(), ans.end());
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
