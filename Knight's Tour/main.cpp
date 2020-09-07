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

const int di[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int dj[] = {2, -2, 1, -1, 2, -2, 1, -1};

const int n = 8;
int visited[n][n];

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n && !visited[i][j];
}

int deg(int i, int j) { 
    int res = 0;
    for (int k = 0; k < 8; k++) { 
        int ni = i + di[k], nj = j + dj[k];
        res += valid(ni, nj);
    }
    return res;
}

void dfs(int i, int j, int c = 1) {
    visited[i][j] = c;
    if (c == 64) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << visited[i][j] << " ";
            cout << "\n";
        }
        exit(0);
    }
    vector<array<int,3>> pos;
    for (int k = 0; k < 8; k++) { 
        int ni = i + di[k], nj = j + dj[k];
        if (valid(ni, nj)) pos.push_back({deg(ni, nj), ni, nj});
    }
    sort(pos.begin(), pos.end()); // Warnsdorff’s Rule 
    for (auto [de, ni, nj] : pos) dfs(ni, nj, c + 1);
    visited[i][j] = 0;
}

void solve() {
    int i, j; cin >> j >> i;
    dfs(i - 1, j - 1);
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
