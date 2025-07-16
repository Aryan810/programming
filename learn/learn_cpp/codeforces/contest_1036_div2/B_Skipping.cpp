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
    
    int n;
    cin >> n;
    vi dp(n+1, 1e16);
    vi a(n);
    rep(i, n) cin >> a[i];
    vi b(n);
    rep(i, n) cin >> b[i];

    vector<vector<pi> >  graph(n+1);
    for (int i=0;i<n;i++){
        if (b[i] > i+1){graph[i+1].push_back({b[i], a[i]});}
        if (i > 1){
            graph[i+1].push_back({i, 0});
        }
    }
    vector<int> dis(n+1, 1e15);
    dis[1] = 0;
    multiset<pi> st;
    st.insert({0, 1});
    while (st.size() > 0){
        auto curr = *st.begin();

        st.erase(st.begin());
        // cout << "lyer" << endl;
        // cout << curr.first << " " << curr.second << endl;

        for (auto & ele: graph[curr.second]){
            if (dis[ele.first] > curr.first + ele.second){
                dis[ele.first] = curr.first + ele.second;
                st.insert({dis[ele.first], ele.first});
                // cout << ele.first << " " << ele.second << endl;

            }
        }
    }
    // for (int i=1;i<=n;i++){
    //     cout << dis[i] << " ";
    // }cout << endl;
    int sm = 0;
    int ans = 0;
    for (int i=1;i<=n;i++){
        sm += a[i-1];
        ans = max(ans, sm - dis[i]);
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