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

void solve(){
    
    int n;
    cin >> n;

    vi a;
    vector<int> cnt(n+2);
    set<int> st;
    rep(i, n){
        int x;
        cin >> x;
        st.insert(x);
        cnt[x] += 1;
        if (cnt[x] == 1){
            a.push_back(x);
        }
    }
    int mxmex = 0;
    for (auto & ele: st){
        if (ele == mxmex){
            mxmex += 1;
        }
    }

    sort(all(a));

    int m = a.size();

    vi cum(m+1, 0);
    cum[0] = 0;
    int sm = 0;
    for (int i=0;i<m;i++){
        sm += cnt[a[i]];
        cum[i+1] = sm;
    }

    vector<int> l, h;
    int extra = 0;
    for (int i=0;i<=mxmex;i++){
        int mn = cnt[i];
        int it = (upper_bound(all(a), i) - a.begin());
        int mx = cnt[i] + cum[m] - cum[it] + extra;
        l.push_back(mn);
        h.push_back(mx);
        extra += max(0ll, cnt[i]-1);
    }
    // for (int i=0;i<l.size();i++){
    //     cout << l[i] << " " << h[i] << endl;
    // }
    sort(all(l));
    sort(all(h));
    for (int i=0;i<=n;i++){
        auto it1 = lower_bound(all(h), i);
        int bef = it1-h.begin();
        auto it2 = upper_bound(all(l), i);
        int aft = l.size() - (it2-l.begin());
        cout << (l.size() - (aft + bef)) << " ";
    }cout << endl;

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