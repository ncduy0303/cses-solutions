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

// bruteforce with a smart pruning strategy: if the cell in front is bad, and both the cells to the left and right are good, then it's impossible to complete

const int n = 7;
 
int ans;
string s; 
bool vis[n][n];
 
bool ok(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n && !vis[i][j];
}
 
void dfs(int idx, int i, int j) {
    if (i == n - 1 && j == 0) {
        if (idx == n * n - 1) ans++;
        return;
    }
    vis[i][j] = true;
    char c = s[idx];
    if ((c == '?' || c == 'U') && ok(i - 1, j) && !(!ok(i - 2, j) && ok(i - 1, j - 1) && ok(i - 1, j + 1))) dfs(idx + 1, i - 1, j); 
    if ((c == '?' || c == 'D') && ok(i + 1, j) && !(!ok(i + 2, j) && ok(i + 1, j - 1) && ok(i + 1, j + 1))) dfs(idx + 1, i + 1, j); 
    if ((c == '?' || c == 'L') && ok(i, j - 1) && !(!ok(i, j - 2) && ok(i - 1, j - 1) && ok(i + 1, j - 1))) dfs(idx + 1, i, j - 1); 
    if ((c == '?' || c == 'R') && ok(i, j + 1) && !(!ok(i, j + 2) && ok(i - 1, j + 1) && ok(i + 1, j + 1))) dfs(idx + 1, i, j + 1); 
    vis[i][j] = false;
}
 
void solve(int tc = 0) {
    cin >> s;
    dfs(0, 0, 0);
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