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



void solve() {
    int n; cin >> n;
    int x[n];
    for (int i = 0; i < n; i++) cin >> x[i];
    ll dp[n][n];
    for (int l = 0; l < n; l++) {
        for (int i = 0, j = i + l; j < n; i++, j++) {
            if (l == 0) dp[i][j] = x[i];
            else if (l == 1) dp[i][j] = max(x[i], x[j]);
            else dp[i][j] = max(x[i] + min(dp[i + 1][j - 1], dp[i + 2][j]),
                                x[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
        }
    }
    cout << dp[0][n - 1] << "\n";
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
