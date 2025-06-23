// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>
const int M = 1e9 + 7;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){
    
    int n;
    cin >> n;
    vector<array<int, 3> > v(n);
    multiset<array<int, 3> > ms;
    int ans = 0;
    for (int i=0;i<n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        int mn = min(a, min(c, b/2));
        ans += mn;
        a -= mn;
        b -= 2*mn;
        c -= mn;
        v[i] = {b, a, c};
        ms.insert({b, a, c});
    }

    while (ms.size() > 1){
        auto f = *(--ms.end());
        ms.erase(--ms.end());
        auto s = *(--ms.end());
        ms.erase(--ms.end());
        int orig = ans;
        // first we take hard from first
        int mn = min(min(f[1], f[0]), min(s[0], s[2]));
        ans += mn;
        f[1] -= mn;
        f[0] -= mn;
        s[0] -= mn;
        s[2] -= mn;

        // second we take hard from second
        mn = min(min(s[1], s[0]), min(f[0], f[2]));
        ans += mn;
        s[1] -= mn;
        s[0] -= mn;
        f[0] -= mn;
        f[2] -= mn;

        ms.insert(f);
        ms.insert(s);
        if (ans == orig){
            break;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}