#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

struct SparseTable {
    vector<vector<int>> dp;
    SparseTable(vector<int> &arr) {
        int n = arr.size(), k = lg(n) + 1;
        dp.resize(k);
        dp[0] = arr;
        for (int j = 1; j < k; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                dp[j].push_back(min(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]));
    }
    int lg(int x) {return 32 - __builtin_clz(x) - 1;}
    int query(int l, int r) {
        int k = lg(r - l + 1);
        return min(dp[k][l], dp[k][r - (1 << k) + 1]);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    SparseTable st(a);
	while (q--) {
		int l, r; cin >> l >> r; l--; r--;
		cout << st.query(l, r) << "\n";
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