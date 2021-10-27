#include <bits/stdc++.h>
 
using namespace std;
 
#define print_op(...) ostream& operator<<(ostream& out, const __VA_ARGS__& u)
template<typename A, typename B> print_op(pair<A, B>) { return out << "(" << u.first << ", " << u.second << ")"; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> print_op(T_container) { out << "{"; string sep; for (const T &x : u) out << sep << x, sep = ", "; return out << "}"; }
template<typename T> void dbg_out(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void dbg_out(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; dbg_out(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}
#ifdef LOCAL
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif
 
using ll = long long;
using ld = long double;
#define ar array
#define sz(x) ((int)x.size())
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++) 
#define all(a) (a).begin(), (a).end()
 
const int MAX_N = 3e3 + 5;
const int MAX_L = 20;
const int MAX_C = 26;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
 
int n, m;
ll ps[MAX_N], aps[MAX_N];
int opt[MAX_N][MAX_N];
ll cost[MAX_N][MAX_N]; 
ll dp[MAX_N][MAX_N]; 
 
// cost[i][j] = min cost to build a school in the range [i..j]
// cost[i][j] = min { apsum_reverse(i, k - 1) + ap_sum(k + 1, j) }, where i <= k <= j
// apsum(i, j) = 1 * a[i] + 2 * a[i + 1] + ... + (j - i + 1) * a[j]
 
// dp[i][j] = min cost to split [1..j] into i-th groups, the last house of group i-th is j
// dp[i][j] = min { dp[i - 1][k - 1] + cost(k, j) }, where i <= k <= j
 
void init_cost() { // O(n^2) using kunth optimisation
    memset(cost, 0x3f, sizeof cost);
    for (int i = 1; i <= n; i++) {
        opt[i][i] = i;
        cost[i][i] = 0;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = opt[i][j - 1]; k <= opt[i + 1][j]; k++) {
                ll ncost = (ps[k] - ps[i - 1]) * k - (aps[k] - aps[i - 1]) + 
                           (aps[j] - aps[k]) - (ps[j] - ps[k]) * k;
                if (cost[i][j] > ncost) {
                    cost[i][j] = ncost;
                    opt[i][j] = k;
                }
            }
        }
    }
}
 
void calc(int i, int l, int r, int ql, int qr) { // O(n * logn) using d&c optimisation
    if (l > r) return;
 
    int mid = (l + r) / 2;
    array<ll,2> res = {LLONG_MAX, -1};
    for (int k = ql; k <= min(mid, qr); k++) 
        res = min(res, {dp[i - 1][k - 1] + cost[k][mid], k});
 
    dp[i][mid] = res[0];
    calc(i, l, mid - 1, ql, res[1]);
    calc(i, mid + 1, r, res[1], qr);
}
 
void solve(int tc = 0) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        ps[i] = ps[i - 1] + x;
        aps[i] = aps[i - 1] + (ll) x * i; 
    }
    init_cost();
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++) 
        calc(i, i, n, i, n - m + i);
    cout << dp[m][n] << "\n";
}
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }
}