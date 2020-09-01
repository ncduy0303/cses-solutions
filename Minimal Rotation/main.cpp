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

int min_rotation(string s) {
    int ans = 0, n = s.size();
    s += s; // concatenate the string to itself to simulate rotating string
    for (int cur = 0; cur < n; cur++) { // complete search with pruning
        for (int i = 0; i < n; i++) {
            if (ans + i == cur || s[ans + i] < s[cur + i]) { 
                cur += max(0, i - 1);
                break;
            }
            if (s[cur + i] < s[ans + i]) {
                ans = cur;
                break;
            }
        }
    }
    return ans;
}

void solve() {
    string s; cin >> s;
    s += s;
    cout << s.substr(min_rotation(s), s.size() / 2) << "\n";
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
