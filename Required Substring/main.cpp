#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e2 + 5;
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

int kmp[MAX_N];

void kmp_preprocess(string s) {
    kmp[0] = -1;
    int i = 0, j = -1;
    while (i < s.size()) {
        while (j >= 0 && s[i] != s[j]) j = kmp[j];
        i++; j++;
        kmp[i] = j;
    }
}

void solve() {
    int n; string s; cin >> n >> s;
    int m = s.size();
    kmp_preprocess(s);
    
    int dp[n + 1][m + 1] = {};
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (char c = 'A'; c <= 'Z'; c++) {
                int k = j;
                while (k && s[k] != c) k = kmp[k];
                if (s[k] == c) k++;
                (dp[i + 1][k] += dp[i][j]) %= MOD;
            }
        }
    }

    ll ans = 0, mul = 1;
    for (int i = n; i >= m; i--) {
        (ans += dp[i][m] * mul) %= MOD;
        (mul *= 26) %= MOD;
    }
    cout << ans << "\n";
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
