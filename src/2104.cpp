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

template<char MIN_CHAR = 'a', int ALPHA = 26> struct SuffixAutomaton {
    int last;
    vector<int> len, link, firstPos;
    vector<array<int, ALPHA>> nxt;

    SuffixAutomaton() : last(0), len(1), link(1, -1), firstPos(1), nxt(1) {}

    SuffixAutomaton(const string &s) : SuffixAutomaton() {
        for (char c : s)
            extend(c);
    }

    int getIndex(char c) {
        return c - MIN_CHAR;
    }

    void extend(char c) {
        int cur = (int) len.size(), i = getIndex(c), p = last;
        len.push_back(len[last] + 1);
        link.emplace_back();
        firstPos.emplace_back(len[last] + 1);
        nxt.emplace_back();
        while (p != -1 && !nxt[p][i]) {
            nxt[p][i] = cur;
            p = link[p];
        }
        if (p != -1) {
            int q = nxt[p][i];
            if (len[p] + 1 == len[q]) {
                link[cur] = q;
            } else {
                int clone = (int) len.size();
                len.push_back(len[p] + 1);
                link.push_back(link[q]);
                firstPos.push_back(firstPos[q]);
                nxt.push_back(nxt[q]);
                while (p != -1 && nxt[p][i] == q) {
                    nxt[p][i] = clone;
                    p = link[p];
                }
                link[q] = link[cur] = clone;
            }
        }
        last = cur;
    }

    int firstMatching(const string &t) {
        int cur = 0;
        for (char c : t) {
            int cc = c - 'a';
            if (!nxt[cur][cc]) return -1;
            cur = nxt[cur][cc];
        }
        return firstPos[cur] - sz(t) + 1;
    }
};

void solve(int tc = 0) {
    string s; int q; cin >> s >> q;
    SuffixAutomaton sa(s);
    while (q--) {
        string t; cin >> t;
        cout << sa.firstMatching(t) << "\n";
    }
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