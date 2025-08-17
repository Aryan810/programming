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
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){
    
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    int inv = 0;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (a[j] < a[i]){
                inv += 1;
            }
        }
    }
    int ans = 1e18;
    int l = -1, r = -1;
    for (int i=0;i<n;i++){
        ordered_multiset<int> st;
        for (int j=i;j<n;j++){
            st.insert(a[j]);
            int change = 0;
            // for i
            auto it1 = st.upper_bound(a[i]+1);
            auto it2 = st.upper_bound(a[i]);
            int big = 0;
            int smal = 0;
            if (it1 != st.end()){
                big = st.size() - (st.order_of_key(*it1));
            }
            if (it2 != st.end()){
                smal = (st.order_of_key(*it2));
            }
            change += big - smal;

         
            if (ans > inv + change){
                l = i+1;
                r = j + 1;
                ans = inv + change;
            }

        }
    }
    cout << l << " " << r << endl;
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