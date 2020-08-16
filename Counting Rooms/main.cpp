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

int n, m;
int visited[MAX_N][MAX_N];
char grid[MAX_N][MAX_N];

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

void dfs(int i, int j) {
    visited[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k], nj = j + dy[k];
        if (0 <= ni && ni < n && 0 <= nj && nj < m && grid[ni][nj] == '.' && !visited[ni][nj]) {
            dfs(ni, nj);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == '.') {
                dfs(i, j);
                ans++;
            }
        }
    }
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
