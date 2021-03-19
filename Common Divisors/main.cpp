#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e6 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n; cin >> n;
	vector<int> cnt(MAX_N);
	while (n--) {
		int x; cin >> x;
		cnt[x]++;
	}
	for (int i = MAX_N - 1; i >= 0; i--) {
		int cur = 0;
		for (int j = i; j < MAX_N; j += i) cur += cnt[j];
		if (cur > 1) {
			cout << i << "\n";
			return;
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