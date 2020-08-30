#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;
const double EPS = 1e-9;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)

struct matrix {
    ll m[2][2];
    matrix (ll a = 0, ll b = 0, ll c = 0, ll d = 0) {
        m[0][0] = a;
        m[0][1] = b;
        m[1][0] = c;
        m[1][1] = d;
    }
    matrix operator* (matrix b) {
        matrix o, a = *this;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    (o.m[i][j] += (a.m[i][k] * b.m[k][j])) %= MOD;
        return o;
    }
};

matrix qexp(matrix A, ll B) {
    if (B == 0) return matrix(1, 0, 0, 1);
    matrix half = qexp(A, B / 2);
    half = half * half;
    if (B % 2) half = half * A;
    return half;
}

void solve() {
    ll n; cin >> n;
    matrix A = matrix(0, 1, 1, 1);
    cout << qexp(A, n + 1).m[0][0] << "\n";
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
