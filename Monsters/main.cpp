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

int n, m, par[MAX_N][MAX_N];
array<int, 2> A;
char grid[MAX_N][MAX_N];

const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
const string dc = "DLUR";

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == '.';
}

bool end(int i, int j) {
    return (i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 'A';
}

void solve() {
    cin >> n >> m;
    queue<array<int, 2>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') A = {i, j};
            if (grid[i][j] == 'M') q.push({i, j});
        }
    }
    q.push(A);
    par[A[0]][A[1]] = -1;
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        if (end(i, j)) { // reach the end
            cout << "YES\n";
            string ans;
            int k = par[i][j];
            while (k != -1) { // backtracking
                i -= di[k]; j -= dj[k]; 
                ans += dc[k];
                k = par[i][j];
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n" << ans << "\n";
            return;
        }
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (valid(ni, nj)) {
                grid[ni][nj] = grid[i][j];
                if (grid[ni][nj] == 'A') par[ni][nj] = k;
                q.push({ni, nj});
            }
        }
    }
    cout << "NO\n";
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
