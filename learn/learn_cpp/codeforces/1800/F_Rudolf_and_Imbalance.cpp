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
    
    int n, m, k;
    cin >> n >> m >> k;

    vi a(n);
    rep(i, n) cin >> a[i];

    vi d(m);
    rep(i, m) cin >> d[i];

    vi f(k);
    rep(i, k) cin >> f[i];

    sort(all(d));
    sort(all(f));
    sort(all(a));
    map<int, int> cnt;
    int mxgape = 0;
    set<int> st;
    for (int i=0;i<n-1;i++){
        cnt[(a[i+1]-a[i])] += 1;
        st.insert(a[i+1]-a[i]);
        mxgape = max(mxgape, a[i+1]-a[i]);
    }
    while (st.size() > 2){
        st.erase(st.begin());
    }
    if (cnt[mxgape] > 1){
        cout << mxgape << endl;return;
    }
    int p = -1;
    int q = -1;
    for (int i=0;i<(n-1);i++){
        if (a[i+1]-a[i] == mxgape){
            p = a[i];
            q = a[i+1];
            break;
        }
    }
    int mid = (p + q)/2;
    set<pair<int, int> > tmp;
    for (int i=0;i<m;i++){
        int curr = d[i];
        if (curr >= mid){
            int tv = f[0] + curr;
            int x = max(abs(tv-p), abs(tv-q));
            if (tv > p && tv < q){tmp.insert({x, tv});}
        }else{
            auto it = lower_bound(all(f), mid-curr);
            if (it != f.end()){
                int tv = *it + curr;
                int x = max(abs(tv-p), abs(tv-q));
                if (tv > p && tv < q){tmp.insert({x, tv});}
            }
            if (it != f.begin()){
                int tv = *(it-1) + curr;
                int x = max(abs(tv-p), abs(tv-q));
                if (tv > p && tv < q){tmp.insert({x, tv});}
            }
            if (it != f.end() && it+1 != f.end()){
                int tv = *(it+1) + curr;
                int x = max(abs(tv-p), abs(tv-q));
                if (tv > p && tv < q){tmp.insert({x, tv});}
            }   
        }
    }

    if (tmp.size() > 0 && tmp.begin()->first < mxgape){
        st.erase(mxgape);
        st.insert(tmp.begin()->first);
    }

    cout << *(--st.end()) << endl;





    
    
    


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