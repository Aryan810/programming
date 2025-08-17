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
int change(int start, int end, vector<pi> & chords){
    int ret = 0;
    for (auto & ele: chords){
        int mn = min(ele.first, ele.second);
        int mx = max(ele.first, ele.second);
        if (!((start >= mn && start <= mx)&&(end >= mn && end <= mx) || ((!(start >= mn && start <= mx))&&(!(end >= mn && end <= mx))))){
            ret += 1;
        }
    }
    return ret;
}
void solve(){
    
    int n, k;
    cin >> n >> k;

    vector<pi> chords;
    set<int> st;
    for (int i=0;i<2*n;i++){
        st.insert(i+1);
    }
    int ans = 0;
    for (int i=0;i<k;i++){
        int f, s;
        cin >> f >> s;
        ans += change(f, s, chords);
        chords.push_back({f, s});
        st.erase(f);
        st.erase(s);
    }
    vector<int> lft;
    for (auto & ele: st){
        lft.push_back(ele);
    }
    int f = 0;
    int s = (n-k);
    int m = lft.size();
    for (int j=0;j<(n-k);j++){
        int start = lft[f%m];
        int end = lft[s%m];
        f += 1;
        s += 1;
        ans += change(start, end, chords);
        chords.push_back({start, end});
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