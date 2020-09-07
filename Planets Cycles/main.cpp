#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 2e5 + 5;
const int MAX_L = 30; // ~ Log(1e9)
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

int n, par[MAX_N], dep[MAX_N], cy[MAX_N];

void dfs(int u, int t = 0) {
    int v = par[u];
    cy[u] = --t;
    if (!cy[v]) dfs(v, t);
    if (cy[v] < 0) { // detect a cycle
        dep[u] = cy[u] = cy[v] - cy[u] + 1;
        for (; v != u; v = par[v]) cy[v] = dep[v] = cy[u];
        return;
    }
    if (cy[u] < 0) {
        cy[u] = cy[v];
        dep[u] = dep[v] + 1;
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> par[i];
    for (int i = 1; i <= n; i++)
        if (!cy[i])
            dfs(i);
    for (int i = 1; i <= n; i++) cout << dep[i] << " ";
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
