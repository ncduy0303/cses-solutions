#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 2e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

const int MAX_L = 30;
 
int n, q, par[MAX_N][MAX_L];
 
int ancestor(int u, int k) {
	for (int i = 0; i < MAX_L; i++) {
		if (k >> i & 1) {
			u = par[u][i];
		}
	}
	return u;
}

void solve() {
    cin >> n >> q;
	for (int u = 1; u <= n; u++) cin >> par[u][0];
	for (int i = 1; i < MAX_L; i++) {
		for (int u = 1; u <= n; u++) {
			par[u][i] = par[par[u][i - 1]][i - 1];
		}
	}
	while (q--) {
		int u, k; cin >> u >> k;
		cout << ancestor(u, k) << "\n";
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