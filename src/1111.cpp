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

const int MAX_N = 1e6 + 5;
const int MAX_L = 20;
const int MAX_C = 26;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int p[2 * MAX_N + 3];
 
string manacher(const string &s) {
    memset(p, 0, sizeof p);
    string t = "$";
    for (char c : s)
        t += '#', t += c;
    t += "#@";
 
    int c = 0, r = 0;
    for (int i = 1; i < (int) t.size() - 1; i++) {
        int mirr = 2 * c - i;
        if (i < r)
            p[i] = min(p[mirr], r - i);
        while (t[i + (p[i] + 1)] == t[i - (p[i] + 1)])
            p[i]++;
        if (p[i] + i > r) {
            c = i;
            r = i + p[i];
        }
    }
 
    int start = 0, mx = 0;
    for (int i = 0; i < sz(t); i++) {
        if (p[i] > mx) {
            if (i % 2) {
                start = (i / 2 - 1) - p[i] / 2 + 1;
            } else {
                start = (i / 2 - 1) - p[i] / 2;
            }
            mx = p[i];
        }
    }
 
    return s.substr(start, mx);
}
 
void solve(int tc = 0) {
    string s; cin >> s;
    cout << manacher(s) << "\n";
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