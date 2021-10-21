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

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template <class T> struct Point {
    T x, y;
    Point() : x(0), y(0) {}
    Point(const T& _x, const T& _y) : x(_x), y(_y) {}

    friend std::ostream& operator<<(std::ostream& out, const Point& p) { return out << p.x << " " << p.y; }
    friend std::istream& operator>>(std::istream& in, Point& p) { return in >> p.x >> p.y; }

    friend bool operator==(const Point& a, const Point& b) { return tie(a.x, a.y) == tie(b.x, b.y); }
    friend bool operator!=(const Point& a, const Point& b) { return tie(a.x, a.y) != tie(b.x, b.y); }
    friend bool operator<(const Point& a, const Point& b) { return tie(a.x, a.y) < tie(b.x, b.y); }

    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator*(const T& d) const { return Point(x * d, y * d); }
    Point operator/(const T& d) const { return Point(x / d, y / d); }

    T dot(const Point& p) const { return x * p.x + y * p.y; }
    T cross(const Point& p) const { return x * p.y - y * p.x; }
    T cross(const Point& a, const Point& b) const { return (a - *this).cross(b - *this); }
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2(y, x); } // [-pi, pi] to x-axis

    Point unit() const { return *this / dist(); } // unit vector
    Point perp() const { return P(-y, x); } // rotates +90 degrees
    Point normal() const { return perp().unit(); }
    Point rotate(const double& a) const { return P(x*cos(a) - y*sin(a), x*sin(a) + y*cos(a)); } // ccw around (0,0)
};

using P = Point<ll>;

vector<P> convexHull(vector<P> pts) {
    if (sz(pts) <= 1) return pts;
    sort(all(pts));
    vector<P> h(sz(pts)+1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(all(pts)))
        for (P p : pts) {
            while (t >= s + 2 && h[t-2].cross(h[t-1], p) < 0) t--;
            h[t++] = p;
        }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}
 
void solve(int tc = 0) {
    int n; cin >> n;
    vector<P> a(n);
    for (P &p : a) cin >> p;
    auto ans = convexHull(a);
    cout << sz(ans) << "\n";
    for (P p : ans) cout << p << "\n";
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