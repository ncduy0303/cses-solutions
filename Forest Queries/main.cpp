#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n, q; cin >> n >> q;
	ll ps[n + 1][n + 1] = {};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c; cin >> c;
			ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + (c == '*');
		}
	}
	while (q--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		cout << ps[x2][y2] + ps[x1 - 1][y1 - 1] - ps[x1 - 1][y2] - ps[x2][y1 - 1] << "\n";
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