#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 2e5 + 5;
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

int N, Q;
ll ft[MAX_N];

void update(int x, int v) {
    for (; x <= N; x += LSOne(x))
        ft[x] += v;
}

ll sum(int x) {
    ll res = 0;
    for (; x; x -= LSOne(x))
        res += ft[x];
    return res;
}

ll rsq(int a, int b) {
    return sum(b) - sum(a - 1);
}

void solve() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        update(i, x);
    }
    while (Q--) {
        char c; cin >> c;
        if (c == '1') {
            int k, u; cin >> k >> u;
            update(k, u - rsq(k, k));
        }
        else {
            int a, b; cin >> a >> b;
            cout << rsq(a, b) << "\n";
        }
    }
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
