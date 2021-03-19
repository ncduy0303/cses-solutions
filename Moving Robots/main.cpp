#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

const int n = 8;
const int d = 4;
const int di[d] = {0, 1, 0, -1};
const int dj[d] = {1, 0, -1, 0};
 
bool ok(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n;
}

void solve() {
    int m; cin >> m;
    double e[n][n] = {};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            e[i][j] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double p[m + 1][n][n] = {};
            p[0][i][j] = 1;
            for (int k = 0; k < m; k++) {
                for (int i2 = 0; i2 < n; i2++) {
                    for (int j2 = 0; j2 < n; j2++) {
                        int cnt = 0;
                        for (int d2 = 0; d2 < d; d2++) {
                            int ni = i2 + di[d2];
                            int nj = j2 + dj[d2];
                            cnt += ok(ni, nj);
                        }
                        for (int d2 = 0; d2 < d; d2++) {
                            int ni = i2 + di[d2];
                            int nj = j2 + dj[d2];
                            if (ok(ni, nj)) p[k + 1][ni][nj] += p[k][i2][j2] / cnt;
                        }
                    }
                }
            }
            for (int i2 = 0; i2 < n; i2++) {
                for (int j2 = 0; j2 < n; j2++) {
                    e[i2][j2] *= (1 - p[m][i2][j2]);
                }
            }
        }
    }
    double ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans += e[i][j];
    cout << fixed << setprecision(6) << ans << "\n";
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