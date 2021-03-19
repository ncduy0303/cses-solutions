#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int k, n; cin >> k >> n;
    multiset<int> ms;
    set<int> st;
    st.insert(0); st.insert(k);
    ms.insert(k);
    while (n--) {
        int x; cin >> x;
        auto r = st.upper_bound(x);
        auto l = prev(r);
        ms.erase(ms.find(*r - *l));
        ms.insert(*r - x);
        ms.insert(x - *l);
        st.insert(x);
        cout << *ms.rbegin() << " ";
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