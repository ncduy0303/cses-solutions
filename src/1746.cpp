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

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++) 
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const int MAX_L = 20;
const int MAX_C = 26;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

// dp[i][x] = the number of arrays for the first elements with the last element = x
// dp[i][x] = dp[i - 1][x - 1] + dp[i - 1][x] + dp[i - 1][x + 1]

void add(int &a, const int &b) {
    a += b;
    if (a > MOD) a -= MOD;
}
 
void solve(int tc = 0) {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<vector<int>> dp(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (a[i] == 0) {
                fill(all(dp[0]), 1);
            } else {
                dp[0][a[i]] = 1;
            }
        } else {
            if (a[i] == 0) {
                for (int j = 1; j <= m; j++) {
                    add(dp[i][j], dp[i - 1][j]);
                    if (j > 1) add(dp[i][j], dp[i - 1][j - 1]);
                    if (j < m) add(dp[i][j], dp[i - 1][j + 1]);
                }
            } else {
                add(dp[i][a[i]], dp[i - 1][a[i]]);
                if (a[i] > 1) add(dp[i][a[i]], dp[i - 1][a[i] - 1]);
                if (a[i] < m) add(dp[i][a[i]], dp[i - 1][a[i] + 1]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) add(ans, dp[n - 1][i]);
    cout << ans << "\n";
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