#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, m;
vector<ar<int,2>> adj[MAX_N];
vector<ll> dist, cnt, mn, mx;
 
void dijk(int s) {
    dist.assign(n + 1, INF);
    cnt.assign(n + 1, 0);
    mn.assign(n + 1, INF);
    mx.assign(n + 1, 0);
    priority_queue<ar<ll,2>,vector<ar<ll,2>>,greater<ar<ll,2>>> pq;
    dist[s] = mn[s] = mx[s] = 0; cnt[s] = 1; pq.push({0, s});
    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u];
                mn[v] = mn[u] + 1;
                mx[v] = mx[u] + 1;
                pq.push({dist[v], v});
            } else if (dist[v] == dist[u] + w) {
                cnt[v] = (cnt[v] + cnt[u]) % MOD;
                mn[v] = min(mn[v], mn[u] + 1);
                mx[v] = max(mx[v], mx[u] + 1);
            }
        }
    } 
}

void solve() {
    cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	dijk(1);
	cout << dist[n] << " " << cnt[n] << " " << mn[n] << " " << mx[n] << "\n";
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