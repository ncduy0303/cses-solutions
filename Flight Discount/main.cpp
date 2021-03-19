#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int n, m;
vector<ar<int,2>> adj[2][MAX_N];
vector<ll> dist[2];
vector<ar<int,3>> el;

void dijk(int t, int s) {
    dist[t].assign(n + 1, INF);
    priority_queue<ar<ll,2>,vector<ar<ll,2>>,greater<ar<ll,2>>> pq;
    dist[t][s] = 0; pq.push({0, s});
    while (pq.size()) {
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
		el.push_back({u, v, w});
	}
	dijk(0, 1);
	dijk(1, n);
	ll ans = INF;
	for (auto [u, v, w] : el) {
		ans = min(ans, dist[0][u] + dist[1][v] + w / 2);
	}
	cout << ans << "\n";
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