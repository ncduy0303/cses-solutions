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



void solve() {
    int n; cin >> n;
    array<int, 3> arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2] = i;
    }
    sort(arr, arr + n); // sort based on arrival day

    priority_queue<ii, vector<ii>, greater<ii>> pq; 
    int ans[n], cnt = 0;
    for (auto x : arr) {
        if (pq.empty() || x[0] <= pq.top().first) ans[x[2]] = ++cnt; // allocate a new room
        else { // can use that room for the next guest
            ans[x[2]] = pq.top().second;
            pq.pop();
        }
        pq.push({x[1], ans[x[2]]});
    }
    cout << cnt << "\n";
    for (int x : ans) cout << x << " ";
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
