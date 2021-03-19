#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 3e18;

template <class T> struct matrix {
    vector<vector<T>> m;
    int r, c;
    matrix() : r(), c() {}
    matrix(int r, int c, T x) : r(r), c(c), m(r, vector<T>(c, x)) {}
    matrix(int n) : matrix(n, n, INF) { // identity matrix
        for (int i = 0; i < n; i++) m[i][i] = 0;
    }
    matrix operator* (matrix<T> b) {
        matrix<T> a = *this;
        assert(a.c == b.r);
        matrix<T> o(a.r, b.c, INF);
        for (int i = 0; i < a.r; i++)
            for (int j = 0; j < b.c; j++)
                for (int k = 0; k < a.c; k++)
                    o.m[i][j] = min(o.m[i][j], a.m[i][k] + b.m[k][j]);
        return o;
    }
    matrix operator^ (ll b) {
        matrix a = *this;
        assert(a.r == a.c);
        matrix<T> o(a.r);
        while (b) {
            if (b % 2) o = o * a;
            a = a * a;
            b /= 2;
        }
        return o;
    }
};

void solve() {
    int n, m, k; cin >> n >> m >> k;
	matrix A(n, n, INF);
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w; u--; v--;
		A.m[u][v] = min(A.m[u][v], (ll)w);
	}
	A = A ^ k;
	cout << (A.m[0][n - 1] < INF ? A.m[0][n - 1] : -1) << "\n";
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