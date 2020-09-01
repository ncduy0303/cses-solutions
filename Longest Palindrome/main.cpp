#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e6 + 5;
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

array<vi, 2> manacher(string s) {
    int n = s.size();
    array<vi,2> p = {vi(n), vi(n)};
    for (int z = 0, l = 0, r = 0; z < 2; z++, l = 0, r = 0) {
        for (int i = 0; i < n; i++) {
            if (i < r) p[z][i] = min(r - i + !z, p[z][l + r - i + !z]);
            int L = i - p[z][i], R = i + p[z][i] - !z;
            while (L > 0 && R < n - 1 && s[L - 1] == s[R + 1]) p[z][i]++, L--, R++;
            if (R > r) l = L, r = R;
        }
    }
    return p;
}

void solve() {
    string s; cin >> s;
    auto p = manacher(s);
    int a = max_element(p[0].begin(), p[0].end()) - p[0].begin();
    int b = max_element(p[1].begin(), p[1].end()) - p[1].begin();
    if (2 * p[0][a] > 2 * p[1][b] + 1)
        cout << s.substr(a - p[0][a], 2 * p[0][a]) << "\n";
    else
        cout << s.substr(b - p[1][b], 2 * p[1][b] + 1) << "\n";
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
