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
const string dc = "RDLU";
 
int n, m, pre[MAX_N][MAX_N];
char grid[MAX_N][MAX_N];
 
bool ok(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m && grid[i][j] == '.';
}
 
bool end(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m && grid[i][j] == 'B';
}

void solve() {
    cin >> n >> m;
	queue<ar<int,2>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'A') q.push({i, j});
		}
	}
	while (q.size()) {
		auto [i, j] = q.front(); q.pop();
		for (int k = 0; k < d; k++) {
			int ni = i + di[k];
			int nj = j + dj[k];
			if (end(ni, nj)) {
				pre[ni][nj] = k;
				string ans;
				while (grid[ni][nj] != 'A') {
					int p = pre[ni][nj];
					ni -= di[p];
					nj -= dj[p];
					ans += dc[p];
				}
				reverse(ans.begin(), ans.end());
				cout << "YES\n" << ans.size() << "\n" << ans << "\n";
				return;
			}
			if (ok(ni, nj)) {
				grid[ni][nj] = '*';
				q.push({ni, nj});
				pre[ni][nj] = k;
			}
		}
	}
	cout << "NO\n";
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