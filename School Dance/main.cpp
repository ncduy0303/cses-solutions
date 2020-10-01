#include <bits/stdc++.h>
 
using namespace std;
 
#define ar array
#define ll long long
 
const int MAX_N = 500 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
 
vector<int> adj[MAX_N];
int match[MAX_N], vis[MAX_N];

bool dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (match[v] == -1 || !vis[match[v]] && dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

void solve() {
    memset(match, -1, sizeof match);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        cnt += dfs(i);
    }
    cout << cnt << "\n";
    for (int i = 1; i <= m; i++) {
        if (match[i] != -1) {
            cout << match[i] << " " << i << "\n";
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    int tc; tc = 1;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}