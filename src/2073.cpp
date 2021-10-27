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

const int MAX_N = 1e5 + 5;
const int MAX_L = 20;
const int MAX_C = 26;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    int sza; char c; bool lz_rev;
    uint32_t priority;
    Node *l, *r;

    Node(char _c) : sza(1), c(_c), lz_rev(false), priority(rng()), l(NULL), r(NULL) {}
};
using pNode = Node*;

int sza(pNode t) {
    return t ? t->sza : 0;
}

void push(pNode t) {
    if (t && t->lz_rev) {
        swap(t->l, t->r);
        if (t->l) t->l->lz_rev ^= true;
        if (t->r) t->r->lz_rev ^= true;
        t->lz_rev = false;
    }
}

void pull(pNode t) {
    if (t) {
        push(t->l);
        push(t->r);
        t->sza = sza(t->l) + sza(t->r) + 1;
    }
}

void heapify(pNode t) {
    if (!t)
        return;
    pNode mx = t;
    if (t->l && t->l->priority > mx->priority)
        mx = t->l;
    if (t->r && t->r->priority > mx->priority)
        mx = t->r;
    if (mx != t) {
        swap(t->priority, mx->priority);
        heapify(mx);
    }
}

void split(pNode t, pNode &l, pNode &r, int pos, int add = 0) { // pos nodes go to pNode l
    if (!t) {
        l = r = NULL;
        return;
    }
    push(t);
    int curPos = add + sza(t->l);
    if (pos < curPos)
        split(t->l, l, t->l, pos, add), r = t;
    else
        split(t->r, t->r, r, pos, curPos + 1), l = t;
    pull(t);
}

void merge(pNode &t, pNode l, pNode r) {
    push(l);
    push(r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->priority > r->priority)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    pull(t);
}

void print(pNode t) {
    if (!t) return;
    push(t);
    print(t->l);
    cout << t->c;
    print(t->r);
}

// Treap

void solve(int tc = 0) {
    int n, q; string s; cin >> n >> q >> s;
    pNode tr = 0;
    for (char c : s) merge(tr, tr, new Node(c));
    while (q--) {
        int l, r; cin >> l >> r; l--; r--;
        pNode p1, p2, p3;
        split(tr, p2, p3, r);
        split(p2, p1, p2, l - 1);
        p2->lz_rev ^= true;
        merge(tr, p1, p2);
        merge(tr, tr, p3);
    }
    print(tr);
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