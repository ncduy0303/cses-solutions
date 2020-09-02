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

int n, num_child[MAX_N];
ll sum_dist[MAX_N];
vi adj[MAX_N];
 
void dfs(int u, int p = 0, int d = 0) {
    sum_dist[1] += d;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
            num_child[u] += num_child[v] + 1;
        }
    }
}

void dfs2(int u, int p = 0) {
    for (int v : adj[u]) {
        if (v != p) {
            sum_dist[v] = sum_dist[u] - (num_child[v] + 1) + (n - num_child[v] - 1);
            dfs2(v, u);
        }
    }
}
 
void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1); 
    dfs2(1);
    for (int i = 1; i <= n; i++)
        cout << sum_dist[i] << " ";
    cout << "\n";
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
