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
    for (ll i = 1; i <= n; i++) { 
        // precompute answer for i < 5
        if (i == 1) cout << "0\n";
        else if (i == 2) cout << "6\n";
        else if (i == 3) cout << "28\n";
        else if (i == 4) cout << "96\n";
        else { // formula for n >= 5
            ll center = (i - 4) * (i - 4) * (i * i - 9);
            ll corner = (i * i - 3) + (i * i - 5) + 2 * (i * i - 4);
            ll middle = (i - 4) * (i * i - 5) + (i - 4) * (i * i - 7); 
            ll ans = (center + 4 * (corner + middle)) / 2; // remove overcounting
            cout << ans << "\n";
        }
    }
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
