#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, m, vis[MAX_N];
vector<ar<int,2>> adj[MAX_N];
vector<int> ans;
 
void dfs(int u) {
	while (adj[u].size()) {
		auto [v, i] = adj[u].back(); adj[u].pop_back();
		if (vis[i]) continue;
		vis[i] = 1;
		dfs(v);
		ans.push_back(i);
	}
}

void solve() {
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        int u = i >> 1, v = i & ((1 << (n - 1)) - 1);
        adj[u].push_back({v, i});
    }
    dfs(0);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n - 1; i++) cout << 0;
    for (int x : ans) cout << x % 2;
    cout << "\n";
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