#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 2e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, par[MAX_N], dep[MAX_N], cy[MAX_N];
 
void dfs(int u, int d = 0) {
    cy[u] = --d;
    int v = par[u];
    if (!cy[v]) dfs(v, d);
    if (cy[v] < 0) {
        cy[u] = cy[v] - cy[u] + 1;
        dep[u] = cy[u];
        while (v != u) {
            dep[v] = cy[v] = cy[u];
            v = par[v];
        }
    } else if (cy[u] < 0) {
        cy[u] = cy[v];
        dep[u] = dep[v] + 1;
    }
}

void solve() {
    cin >> n;
    for (int u = 1; u <= n; u++) cin >> par[u];
    for (int u = 1; u <= n; u++) {
        if (cy[u]) continue;
        dfs(u);
    }
    for (int i = 1; i <= n; i++) cout << dep[i] << " ";
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