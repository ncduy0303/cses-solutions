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
 
// tree query using eulerian ordering and mo's algorithm (classic distinct query)

const int BLOCK = sqrt((double)MAX_N);

struct node{
    int l, r, id;
} query[MAX_N];

bool cmp(node a, node b){
    if (a.l/BLOCK != b.l/BLOCK)
        return a.l/BLOCK < b.l/BLOCK;
    else
        return a.r < b.r;
}
 
int n, q, col[MAX_N], arr[2 * MAX_N], ans[MAX_N], cnt[MAX_N], tin[MAX_N], tout[MAX_N], timer, cur;
vi adj[MAX_N];
 
void add(int idx) {
    if (cnt[arr[idx]] == 0) cur++;
    cnt[arr[idx]]++;
}

void subtract(int idx) {
    if (cnt[arr[idx]] == 1) cur--;
    cnt[arr[idx]]--;
}
 
void dfs(int u, int p = 0) {
    tin[u] = ++timer;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    tout[u] = ++timer;
}

void compress() { // compress used colours from 1e9 to 2e5 
	map<int, int> mp;
	vi tmp(col + 1, col + 1 + n);
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < n; i++) 
		mp[tmp[i]] = i;
	for (int i = 1; i <= n ; i++) 
		col[i] = mp[col[i]];
}

void mo_algo() {
    sort(query + 1, query + n + 1, cmp);
    int curL = 0, curR = 0;
    for (int i = 1; i <= n; i++) {
        int L = query[i].l, R = query[i].r;
        while (curL < L) subtract(curL++);
        while (curL > L) add(--curL);
        while (curR < R) add(++curR);
        while (curR > R) subtract(curR--);
        ans[query[i].id] = cur;
    }
}
 
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> col[i];
    map_colors();
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) arr[tin[i]] = arr[tout[i]] = col[i];
    for (int i = 1; i <= n; i++) {
        query[i].l = tin[i];
        query[i].r = tout[i];
        query[i].id = i;
    }
    mo_algo();
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
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