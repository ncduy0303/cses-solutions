#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

template <class T> struct matrix {
    vector<vector<T>> m;
    int r, c;
    matrix() : r(), c() {}
    matrix(int r, int c, T x) : r(r), c(c), m(r, vector<T>(c, x)) {}
    matrix(int n) : matrix(n, n, 0) { // identity matrix
        for (int i = 0; i < n; i++) m[i][i] = 1;
    }
    matrix operator* (matrix<T> b) {
        matrix<T> a = *this;
        assert(a.c == b.r);
        matrix<T> o(a.r, b.c, 0);
        for (int i = 0; i < a.r; i++)
            for (int j = 0; j < b.c; j++)
                for (int k = 0; k < a.c; k++)
                    o.m[i][j] = (o.m[i][j] + a.m[i][k] * b.m[k][j]) % MOD;
        return o;
    }
    matrix operator^ (ll b) {
        assert(r == c);
        matrix<T> a(r, c, 0);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                a.m[i][j] = m[i][j];
        matrix<T> o(r);
        while (b) {
            if (b % 2) o = o * a;
            a = a * a;
            b /= 2;
        }
        return o;
    }
};

void solve() {
    ll n; cin >> n;
	matrix A(1, 2, 0);
	A.m[0][0] = 0; A.m[0][1] = 1;
	matrix B(2, 2, 0);
	B.m[0][0] = 0; B.m[0][1] = 1;
	B.m[1][0] = 1; B.m[1][1] = 1;
	A = A * (B ^ n);
	cout << A.m[0][0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}