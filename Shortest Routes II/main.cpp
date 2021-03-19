#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 5e2 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, m, q;
ll dist[MAX_N][MAX_N];

void solve() {
    cin >> n >> m >> q;
    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = min(dist[u][v], (ll)w);
    }
    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }
    }
    while (q--) {
        int u, v; cin >> u >> v;
        cout << (dist[u][v] < INF ? dist[u][v] : -1) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}