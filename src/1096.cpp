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

template<int _MOD> struct Modular {
    int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
    Modular() { v = 0; }
    Modular(ll _v) { v = int((-_MOD < _v && _v < _MOD) ? _v : _v % _MOD); if (v < 0) v += _MOD; }
    friend std::ostream& operator<<(std::ostream& out, const Modular& n) { return out << int(n); }
    friend std::istream& operator>>(std::istream& in, Modular& n) { ll v_; in >> v_; n = Modular(v_); return in; }
    friend bool operator==(const Modular& a, const Modular& b) { return a.v == b.v; }
    friend bool operator!=(const Modular& a, const Modular& b) { return a.v != b.v; }
    friend bool operator<(const Modular& a, const Modular& b) { return a.v < b.v; }
    Modular& operator+=(const Modular& m) { if ((v += m.v) >= _MOD) v -= _MOD; return *this; }
    Modular& operator-=(const Modular& m) { if ((v -= m.v) < 0) v += _MOD; return *this; }
    Modular& operator*=(const Modular& m) { v = int((ll)v*m.v%_MOD); return *this; }
    Modular& operator/=(const Modular& m) { return (*this) *= inverse(m); }
    Modular operator-() const { return Modular(-v); }
    Modular& operator++() { return *this += 1; }
    Modular& operator--() { return *this -= 1; }
    friend Modular power(Modular a, ll p) {
        Modular ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans; 
    }
    friend Modular inverse(const Modular& a) { assert(a.v != 0); return power(a, _MOD-2); }
    friend Modular operator+(Modular a, const Modular& b) { return a += b; }
    friend Modular operator-(Modular a, const Modular& b) { return a -= b; }
    friend Modular operator*(Modular a, const Modular& b) { return a *= b; }
    friend Modular operator/(Modular a, const Modular& b) { return a /= b; }
    friend Modular operator++(Modular& a, int) { Modular r = a; ++a; return r; }friend Modular operator--(Modular& a, int) { Modular r = a; --a; return r; }
};

using mint = Modular<MOD>;

template<typename T> struct Matrix {
    int n, m;
    vector<vector<T>> mat;
    Matrix(int _n, int _m) : n(_n), m(_m), mat(n, vector<T>(m)) {}
    Matrix(int _n) : Matrix(_n, _n) { for (int i = 0; i < n; i++) mat[i][i] = 1; } // identity matrix
    Matrix(const vector<vector<T>> &_mat) : n((int) _mat.size()), m((int) _mat[0].size()), mat(_mat) {}

    Matrix& operator += (const Matrix &other) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                mat[i][j] += other.mat[i][j];
        return *this;
    }
    Matrix& operator -= (const Matrix &other) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                mat[i][j] -= other.mat[i][j];
        return *this;
    }
    
    Matrix operator * (const Matrix &other) const {
        Matrix ret(n, other.m);
        for (int i = 0; i < n; i++)
            for (int k = 0; k < m; k++)
                for (int j = 0; j < other.m; j++)
                    ret.mat[i][j] += mat[i][k] * other.mat[k][j];
        return ret;
    }
    
    friend Matrix operator + (Matrix a, const Matrix &b) { return a += b; }
    friend Matrix operator - (Matrix a, const Matrix &b) { return a -= b; }
    Matrix& operator *= (const Matrix &other) { return *this = *this * other; }
    
    vector<T>& operator [] (int i) { return mat[i]; }
    
    friend Matrix power(Matrix a, long long b) {
        Matrix ret(a.n);
        while (b > 0) {
            if (b & 1) ret *= a;
            a *= a;
            b >>= 1;
        }
        return ret;
    }
    
    friend ostream& operator << (ostream &os, const Matrix &a) { return os << a.mat; }
    void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cout << mat[i][j] << " ";
            cout << "\n";
        }
    }
};

void solve(int tc = 0) {
    ll n; cin >> n;
    Matrix<mint> A(1, 6), B(6, 6);
    A.mat[0][5] = 1;
    for (int i = 0; i < 6; i++) B.mat[i][5] = 1;
    for (int i = 0; i < 5; i++) B.mat[i + 1][i] = 1;
    A = A * power(B, n);
    cout << A.mat[0][5] << "\n";
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