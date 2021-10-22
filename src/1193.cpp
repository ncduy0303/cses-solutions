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

const int MAX_N = 1e3 + 5;
const int MAX_L = 20;
const int MAX_C = 26;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

const int d = 4;
const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};
const string ds = "RDLU";
 
int n, m, pre[MAX_N][MAX_N];
char grid[MAX_N][MAX_N];
 
bool ok(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m && grid[i][j] != '#' && pre[i][j] == -1;
}
 
bool end(int i, int j) {
    return grid[i][j] == 'B';
}
 
void solve(int tc = 0) {
    cin >> n >> m;
    queue<ar<int,2>> que;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') que.push({i, j});
        }
    }
    memset(pre, -1, sizeof pre);
    while (!que.empty()) {
        auto [i, j] = que.front(); que.pop();
        for (int k = 0; k < d; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ok(ni, nj)) {
                que.push({ni, nj});
                pre[ni][nj] = k;
                if (end(ni, nj)) {
                    string ans;
                    while (grid[ni][nj] != 'A') {
                        dbg(ni, nj);
                        int nk = pre[ni][nj];
                        ans += ds[nk];
                        ni -= di[nk];
                        nj -= dj[nk];
                    }
                    reverse(all(ans));
                    cout << "YES\n" << sz(ans) << "\n" << ans << "\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
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