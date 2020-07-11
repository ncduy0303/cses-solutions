#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
const int MAX_N = 8;
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
 
int row[MAX_N], col[MAX_N], d1[2 * MAX_N], d2[2 * MAX_N], blocked[MAX_N][MAX_N];
int n = 8, ans = 0;
 
void place(int c) {
    if (c == n) {
        ans++;
        return;
    }
    if (col[c]) place(c + 1);
    else {
        for (int r = 0; r < n; r++) {
            if (!blocked[r][c] && !row[r] && !d1[r + c] && !d2[r - c + n]) {
                blocked[r][c] = row[r] = d1[r + c] = d2[r - c + n] = 1;
                place(c + 1);
                blocked[r][c] = row[r] = d1[r + c] = d2[r - c + n] = 0;
            }
        }
    }
}
 
void solve() {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            char x; cin >> x;
            if (x == '*') blocked[r][c] = 1;
        }
    }
    place(0);
    cout << ans;
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