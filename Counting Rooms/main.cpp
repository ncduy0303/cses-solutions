#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e3 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

const int d = 4;
const int di[d] = {0, 1, 0, -1};
const int dj[d] = {1, 0, -1, 0};
 
int n, m;
char grid[MAX_N][MAX_N];
 
bool ok(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m && grid[i][j] == '.';
}
 
void dfs(int i, int j) {
	grid[i][j] = '*';
	for (int k = 0; k < d; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		if (ok(ni, nj)) dfs(ni, nj);
	}
}

void solve() {
    cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ok(i, j)) {
				dfs(i, j);
				ans++;
			}
		}
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