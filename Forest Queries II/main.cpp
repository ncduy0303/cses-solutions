#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e3 + 5;
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

int N, Q, ft[MAX_N][MAX_N];
char grid[MAX_N][MAX_N];

void update(int x, int y, int v) {
    for (int tx = x; tx <= N; tx += LSOne(tx))
        for (int ty = y; ty <= N; ty += LSOne(ty))
            ft[tx][ty] += v;
}

int sum(int x, int y) {
    int res = 0;
    for (int tx = x; tx; tx -= LSOne(tx))
        for (int ty = y; ty; ty -= LSOne(ty))
            res += ft[tx][ty];
    return res;
}

int query(int x1, int y1, int x2, int y2) {
    return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
}

void solve() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '*') update(i, j, 1);
        }
    }
    while (Q--) {
        char c; cin >> c;
        if (c == '1') {
            int x, y; cin >> x >> y;
            if (grid[x][y] == '*') {
                update(x, y, -1);
                grid[x][y] = '.';
            }
            else {
                update(x, y, 1);
                grid[x][y] = '*';
            }
        }
        else {
            int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
            cout << query(x1, y1, x2, y2) << "\n";
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
