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
 
int n, m, visited[2 * MAX_N], in[MAX_N], out[MAX_N]; 
vii adj[MAX_N];
vi ans;
 
void dfs(int u) {
    for (auto [v, e] : adj[u]) {
        if (!visited[e]) { // the edge is unvisited
            visited[e] = 1;
            dfs(v);
        }
    }
    ans.push_back(u);
}
 
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        out[u]++; in[v]++;
    }
    for (int i = 2; i <= n - 1; i++) {
        if (in[i] != out[i]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    if (in[1] + 1 != out[1] || in[n] != out[n] + 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    dfs(1);
    if (ans.size() != m + 1) cout << "IMPOSSIBLE\n";
    else {
        reverse(ans.begin(), ans.end());
        for (int x : ans) cout << x << " ";
        cout << "\n";
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