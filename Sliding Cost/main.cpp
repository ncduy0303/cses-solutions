#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    ordered_set<ar<int,2>> os;
    for (int i = 0; i < k; i++) os.insert({a[i], i});
    int med = (*os.find_by_order((k - 1) / 2))[0];
    ll ans = 0;
    for (int i = 0; i < k; i++) ans += abs(a[i] - med);
    cout << ans << " ";
    for (int i = 0, j = k; j < n; i++, j++) {
        os.erase({a[i], i});
        os.insert({a[j], j});
        int pre = med;
        med = (*os.find_by_order((k - 1) / 2))[0];
        ans -= abs(a[i] - pre);
        ans += abs(a[j] - med);
        if (k % 2 == 0) ans -= (med - pre);
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}