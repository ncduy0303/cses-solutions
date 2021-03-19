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

bool cmp(ar<int,3> a, ar<int,3> b) {
    return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
}

void solve() {
    int n; cin >> n;
	vector<ar<int,3>> a(n);
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		a[i] = {l, r, i};
	}
	sort(a.begin(), a.end(), cmp);
	vector<int> ans1(n), ans2(n);
	ordered_set<ar<int,2>> os1, os2;
	for (int i = 0, j = n - 1; i < n; i++, j--) {
		ans1[a[j][2]] = os1.order_of_key({a[j][1] + 1, -1});
		ans2[a[i][2]] = i - os2.order_of_key({a[i][1], -1});
		os1.insert({a[j][1], j});
		os2.insert({a[i][1], i});
	}
	for (int x : ans1) cout << (x > 0) << " ";
	cout << "\n";
	for (int x : ans2) cout << (x > 0) << " ";
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