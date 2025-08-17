// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
// using namespace atcoder;
// using mint = modint;
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define each(x, a) for (auto &x : a)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pi pair<int, int>
#define p(a, b) pair<a, b>
#define vi vector<int>
#define vii vector<int>::iterator
#define vvi vector<vector<int> >
#define vv(x) vector<vector<x> >
#define PRECISION(x) cout << fixed << setprecision(x);
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define umap(x, y) unordered_map<x, y, custom_hash>
const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){
    
    int n, m, l;
    cin >> n >> m >> l;

    vector<pi> hur(n);
    vector<pi> pu(m);
    for (int i=0;i<n;i++) cin >> hur[i].first >> hur[i].second;
    for (int i=0;i<m;i++) cin >> pu[i].first >> pu[i].second;

    int ind = 0;
    int pind = 0;
    int k = 1;
    int ans = 0;
    multiset<int> v;
    while (ind < n){
        auto curr = hur[ind];
        int l=1, h=curr.first - 1;
        if (ind > 0){
            l = hur[ind-1].second + 1;
        }
        // cout << ind << " " << l << " " << h << endl;
        while (pind < m && pu[pind].first <= h){
            v.insert(pu[pind].second);
            pind += 1;
        }
        // for (auto & ele: v){
        //     cout << ele << " ";
        // }cout << endl;
        int req = curr.second - curr.first + 2;
        // cout << req << endl;
        while (v.size() > 0 && k < req){
            k += *(--v.end());
            v.erase(--v.end());
            ans += 1;
        }
        if (k < req){
            cout << -1 << endl;return;
        }
        ind += 1;
    }
    cout << ans << endl;

}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}