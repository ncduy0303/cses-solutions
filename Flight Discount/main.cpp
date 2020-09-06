#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e5 + 5;
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

int n, m;
vii adj[2][MAX_N];
vi dist[2];

void dijkstra(int s, int t) {
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push({0, s});
    dist[t].assign(n + 1, INF);
    dist[t][s] = 0;
    while (!pq.empty()) { 
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[t][u]) continue;
        for (auto [v, w] : adj[t][u]) {
            if (dist[t][v] > dist[t][u] + w) {
                dist[t][v] = dist[t][u] + w;
                pq.push({dist[t][v], v});
            }
        }
    } 
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[0][u].push_back({v, w});
        adj[1][v].push_back({u, w});
    }
    dijkstra(1, 0); 
    dijkstra(n, 1);
    ll ans = INF;
    for (int u = 1; u <= n; u++)
        for (auto [v, w] : adj[0][u])
            ans = min(ans, dist[0][u] + dist[1][v] + w / 2);
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
