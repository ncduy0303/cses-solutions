#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, m, k;
vector<ar<int,2>> adj[MAX_N];
vector<ll> cnt;
 
void dijk(int s) {
    cnt.assign(n + 1, 0);
    priority_queue<ar<ll,2>,vector<ar<ll,2>>,greater<ar<ll,2>>> pq;
    pq.push({0, s});
    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        cnt[u]++;
        if (cnt[u] > k) continue;
        if (u == n) cout << d << " ";
        for (auto [v, w] : adj[u]) {
			pq.push({d + w, v});
        }
    } 
	cout << "\n";
}

void solve() {
    cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	dijk(1);
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