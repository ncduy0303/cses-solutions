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
int arr[MAX_N], dp[MAX_N][MAX_L];
 
void build_sparse_table() {
    for (int i = 1; i <= N; i++)
        dp[i][0] = arr[i];
    for (int j = 1; j < MAX_L; j++) 
        for (int i = 1; i + (1 << j) <= N + 1; i++)
            dp[i][j] = dp[i][j - 1] ^ dp[i + (1 << (j - 1))][j - 1];
}

int query(int a, int b) {
    int k = b - a + 1;
    int sum = 0;
    for (int i = 0; i < MAX_L; i++) {
        if (k & (1 << i)) {
            sum ^= dp[a][i];
            a += (1 << i);
        }
    }
    return sum;
}
 
void solve() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    build_sparse_table();
    while (Q--) {
        int a, b; cin >> a >> b;
        cout << query(a, b) << "\n";
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
