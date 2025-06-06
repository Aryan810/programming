#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve() {
    int n;
    cin >> n;

    int curr = 0;
    array<int, 3> last = {1, 2, 3};

    for (int i = 0; i < 76; i++) {
        cout << "? " << last[0] << " " << last[1] << " " << last[2] << endl;
        cout.flush();

        int got;
        if (!(cin >> got)) return;

        if (got == -1) return;

        if (got == 0) {
            cout << "! " << last[0] << " " << last[1] << " " << last[2] << endl;
            cout.flush();
            return;
        } else {
            last[curr] = got;
            curr = (curr + 1) % 2;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while (test--) {
        solve();
    }

    return 0;
}
