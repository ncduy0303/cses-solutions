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
    int r[n];
    double ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> r[i];
        for (int j = 0; j < i; j++) {
            int mn = min(r[i], r[j]);
            int c = mn * (mn - 1) / 2; 
            if (r[j] > r[i]) c += r[i] * (r[j] - r[i]);
            double p = (double)c / (r[i] * r[j]); 
            // c           = no. of cases of ivnersions (r[j] > r[i] and j < i) for pair (i, j)
            // r[i] * r[j] = total no. of cases for pair (i, j)
            // p           = probability that an inversion occurs for pair (i, j)
            ans += p; 
            // E(sum of Xi) = sum of E(Xi)
            // E(Xi) = 0 * P(Xi = 0) + 1 * P(Xi = 1) = p
        }
    }
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
