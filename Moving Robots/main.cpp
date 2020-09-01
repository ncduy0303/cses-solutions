#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;
const double EPS = 1e-9;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)

const int n = 8;

void solve() {
    int k; cin >> k;
    double e[n][n];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            e[i][j] = 1; // after 1st turn, E(X) = 1 for all individual square since the robot will definitely leave that square
    // Formula: E(aX) = a * E(X) = a * sum of all (x * P(X = x))
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double dp[k + 1][n][n] = {};
            dp[0][i][j] = 1; // after 0th turn, the (i, j) robot is at (i, j)
            // dp[k2][i2][j2] = probability of the (i, j) robot is at (i2, j2) after k2-th turn
            // 1 - dp[k2][i2][j2] = probability of the (i, j) robot is not at (i2, j2) after k2-th turn
            for (int k2 = 0; k2 < k; k2++) {
                for (int i2 = 0; i2 < n; i2++) {
                    for (int j2 = 0; j2 < n; j2++) {
                        int d = (i2 > 0) + (i2 < n - 1) + (j2 > 0) + (j2 < n - 1);
                        if (i2 > 0)     dp[k2 + 1][i2 - 1][j2] += dp[k2][i2][j2] / d; 
                        if (i2 < n - 1) dp[k2 + 1][i2 + 1][j2] += dp[k2][i2][j2] / d; 
                        if (j2 > 0)     dp[k2 + 1][i2][j2 - 1] += dp[k2][i2][j2] / d; 
                        if (j2 < n - 1) dp[k2 + 1][i2][j2 + 1] += dp[k2][i2][j2] / d; 
                    }
                }
            }
            for (int i2 = 0; i2 < n; i2++)
                for (int j2 = 0; j2 < n; j2++)
                    e[i2][j2] *= (1 - dp[k][i2][j2]);
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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int tc; tc = 1;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t  << ": ";
        solve();
    }
}
