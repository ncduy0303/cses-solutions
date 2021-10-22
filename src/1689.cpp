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

// Warnsdorff's rule

void solve(int tc = 0) {
    int i, j; cin >> j >> i; i--; j--;
    dfs(i, j, 1);
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