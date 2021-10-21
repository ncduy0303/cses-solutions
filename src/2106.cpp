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

template<char MIN_CHAR = '$', int ALPHA = 256> struct SuffixArray {
    int n;
    string s;
    vector<int> pos, rnk, lcp;

    SuffixArray(const string &_s) : n((int) _s.size() + 1), s(_s), pos(n), rnk(n), lcp(n - 1) {
        s += MIN_CHAR;
        buildSA();
        buildLCP();
    }

    void buildSA() {
        vector<int> cnt(max(ALPHA, n));
        for (int i = 0; i < n; i++) cnt[s[i]]++;
        for (int i = 1; i < ALPHA; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) pos[--cnt[s[i]]] = i;
        for (int i = 1; i < n; i++) rnk[pos[i]] = rnk[pos[i - 1]] + (s[pos[i]] != s[pos[i - 1]]);

        for (int k = 0; (1 << k) < n; k++) {
            vector<int> npos(n), nrnk(n), ncnt(n);
            for (int i = 0; i < n; i++) pos[i] = (pos[i] - (1 << k) + n) % n;
            for (int i = 0; i < n; i++) ncnt[rnk[i]]++;
            for (int i = 1; i < n; i++) ncnt[i] += ncnt[i - 1];
            for (int i = n - 1; i >= 0; i--) npos[--ncnt[rnk[pos[i]]]] = pos[i];
            for (int i = 1; i < n; i++) {
                pair<int,int> cur = {rnk[npos[i]], rnk[(npos[i] + (1 << k)) % n]};
                pair<int,int> pre = {rnk[npos[i - 1]], rnk[(npos[i - 1] + (1 << k)) % n]};
                nrnk[npos[i]] = nrnk[npos[i - 1]] + (cur != pre);
            }
            pos = npos; rnk = nrnk;
        }
    }

    void buildLCP() {
        for (int i = 0, k = 0; i < n - 1; i++, k = max(k - 1, 0)) {
            int j = pos[rnk[i] - 1];
            while (s[i + k] == s[j + k]) k++;
            lcp[rnk[i] - 1] = k;
        }
    }

    string mxRepSubstr() {
        int mx = 0;
        for (int i = 0; i < sz(lcp); i++) {
            if (lcp[i] > lcp[mx]) {
                mx = i;
            }
        }
        if (lcp[mx] == 0) {
            return "-1";
        } else {
            return s.substr(pos[mx], lcp[mx]);
        } 
    }
};

void solve(int tc = 0) {
    string s; cin >> s;
    SuffixArray sa(s);
    cout << sa.mxRepSubstr() << "\n";
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