#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

const int n = 8;
const int d = 8;
const int di[d] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dj[d] = {2, -2, 2, -2, 1, -1, 1, -1};
 
int vis[n][n];

bool ok(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n && !vis[i][j];
}
 
int deg(int i, int j) {
	int cnt = 0;
	for (int k = 0; k < d; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		cnt += ok(ni, nj);
	}
	return cnt;
}
 
void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << vis[i][j] << " ";
        cout << "\n";
    }
}
 
void dfs(int i, int j, int t) {
	vis[i][j] = t;
	if (t == n * n) {
		print();
		exit(0);
	}
	vector<ar<int,3>> pos;
	for (int k = 0; k < d; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		if(ok(ni, nj)) pos.push_back({deg(ni, nj), ni, nj});
	}
	sort(pos.begin(), pos.end());
	for (auto [_, ni, nj] : pos) dfs(ni, nj, t + 1);
	vis[i][j] = 0;
}

void solve() {
    int i, j; cin >> j >> i; i--; j--;
	dfs(i, j, 1);
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