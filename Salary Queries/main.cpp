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
    int n, q; cin >> n >> q;
	vector<int> a(n);
	ordered_set<ar<int,2>> os;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		os.insert({a[i], i});
	}
	while (q--) {
		char c; cin >> c;
		if (c == '!') {
			int i, x; cin >> i >> x; i--;
			os.erase({a[i], i});
			a[i] = x;
			os.insert({a[i], i});
		} else {
			int l, r; cin >> l >> r;
			cout << os.order_of_key({r + 1, -1}) - os.order_of_key({l, -1}) << "\n";
		}
	}
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