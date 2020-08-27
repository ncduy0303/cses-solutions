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

const int n = 7;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};

string s;
bool visited[n][n];

int backtrack(int x, int y, int i, char m) {
    if (i == n * n - 1) return 1;    // going through all squares
    if (visited[0][n - 1]) return 0; // reach destination (lower-left square) before going through all squares

    // pruning
    if (m == 'L' && (x == 0     || visited[x - 1][y]) && y > 0 && y < n - 1 && !visited[x][y - 1] && !visited[x][y + 1]) return 0;
    if (m == 'R' && (x == n - 1 || visited[x + 1][y]) && y > 0 && y < n - 1 && !visited[x][y - 1] && !visited[x][y + 1]) return 0;
    if (m == 'U' && (y == 0     || visited[x][y - 1]) && x > 0 && x < n - 1 && !visited[x - 1][y] && !visited[x + 1][y]) return 0;
    if (m == 'D' && (y == n - 1 || visited[x][y + 1]) && x > 0 && x < n - 1 && !visited[x - 1][y] && !visited[x + 1][y]) return 0;

    if (s[i] == '?') {
        int cnt = 0;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1 || visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            cnt += backtrack(nx, ny, i + 1, "ULDR"[d]);
            visited[nx][ny] = 0;
        }
        return cnt;
    }
    
    if (s[i] == 'L') x--;
    if (s[i] == 'R') x++;
    if (s[i] == 'U') y--;
    if (s[i] == 'D') y++;
    if (x < 0 || x > n - 1 || y < 0 || y > n - 1 || visited[x][y]) return 0;
    visited[x][y] = 1;
    int cnt = backtrack(x, y, i + 1, s[i]);
    visited[x][y] = 0;
    return cnt;
}

void solve() {
    cin >> s;
    visited[0][0] = 1;
    cout << backtrack(0, 0, 0, 0) << "\n";
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
