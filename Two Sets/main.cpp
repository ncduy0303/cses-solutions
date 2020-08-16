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
    ll n; cin >> n;
    if (n * (n + 1) % 4) {
        cout << "NO\n";
        return;
    }
    ll sum = n * (n + 1) / 4;
    vi a, b;
    // greedy approach
    for (int i = n; i >= 1; i--) {
        if (sum >= i) {
            sum -= i;
            a.push_back(i);
        }
        else {
            b.push_back(i);
        }
    }
    cout << "YES";
    cout << "\n" << a.size() << "\n";
    for (int x : a) cout << x << " ";
    cout << "\n" << b.size() << "\n";
    for (int x : b) cout << x << " ";
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
