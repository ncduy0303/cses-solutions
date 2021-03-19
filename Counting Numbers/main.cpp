#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<int> num;
ll dp[19][10][2][2];
 
ll memo(int pos, int pre, bool flag1, bool flag2) {
	if (pos == (int) num.size()) return 1;
	if (dp[pos][pre][flag1][flag2] != -1) return dp[pos][pre][flag1][flag2];
	ll res = 0; int lmt = (flag1) ? 9 : num[pos];
	for (int i = 0; i <= lmt; i++) {
		bool nflag1 = flag1 | (i < lmt);
		bool nflag2 = flag2 | (i > 0);
		if (i != pre || (!flag2 && i == 0)) res += memo(pos + 1, i, nflag1, nflag2);
	}
	return dp[pos][pre][flag1][flag2] = res;
}
 
ll calc(ll n) {
	if (n == -1) return 0;
	if (n == 0) return 1;
	num.clear();
	while (n) {
		num.push_back(n % 10);
		n /= 10;
	}
	reverse(num.begin(), num.end());
	memset(dp, -1, sizeof dp);
	return memo(0, 0, 0, 0);
}

void solve() {
    ll a, b; cin >> a >> b;
	cout << calc(b) - calc(a - 1) << "\n";
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