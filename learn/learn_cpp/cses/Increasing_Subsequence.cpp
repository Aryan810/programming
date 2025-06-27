// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
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
int dp[200001];

void solve(){
    
    int n;
    cin >> n;

    vi a(n);
    rep(i, n) cin >> a[i];

    set<pair<int, int> > st;
    for (int i=0;i<n;i++){
        auto it = st.lower_bound({a[i], -1});
        if (it == st.begin()){
            dp[i] = 1;
        }else{
            it--;
            dp[i] = it->second + 1;
        }
        auto it1 = st.upper_bound({a[i], -1});
        vector<pair<int,int> > todel;
        while (it1 != st.end() && it1->second <= dp[i]){
            todel.push_back(*it1);
            it1++;
        }
        for (auto & ele: todel){    
            st.erase(ele);
        }
        st.insert({a[i], dp[i]});

    }
    int ans = 0;
    for (int i=0;i<n;i++){
        // cout << dp[i] << " ";
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;


}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test = 1;

    while(test--){
        solve();
    }

    return 0;
}