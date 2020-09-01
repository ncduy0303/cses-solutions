#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 3e18 + 7;
const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)

int N, M, K;

struct matrix {
    vvi m = vvi(N, vi(N, INF));
    matrix operator* (matrix b) {
        matrix o, a = *this;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    o.m[i][j] = min(o.m[i][j], a.m[i][k] + b.m[k][j]);
        return o;
    }
};

matrix qexp(matrix A, int B) {
    if (B == 0) {
        matrix base = matrix();
        for (int i = 0; i < N; i++) base.m[i][i] = 0;
        return base;
    }
    matrix half = qexp(A, B / 2);
    half = half * half;
    if (B % 2) half = half * A;
    return half;
}

void solve() {
    cin >> N >> M >> K;
    matrix A;
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        A.m[u - 1][v - 1] = min(A.m[u - 1][v - 1], (ll)w); // there can be more than 1 edge connecting u to v in this problem
    }
    A = qexp(A, K);
    ll ans = A.m[0][N - 1];
    if (ans >= INF / 2)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int tc; tc = 1;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t  << ": ";
        solve();
    }
}