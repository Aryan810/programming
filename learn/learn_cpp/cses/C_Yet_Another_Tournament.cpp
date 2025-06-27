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
    int m;
    cin >> m;
    map<int, vector<int> > ind;
    vi a(n);
    rep(i, n){
        int x;
        cin >> x;
        ind[x].push_back(i);
        a[i] = x;
    }
    vi b = a;
    sort(all(a));

    int tmp = m;
    int i;
    set<int> st;
    for (i=0;i<n;i++){
        if (tmp >= a[i]){
            tmp -= a[i];
            st.insert(a[i]);
        }else{
            break;
        }
    }
    if (st.size() == 0){
        cout << n + 1 << endl;return;
    }
    if (i >= n){
        cout << 1 << endl;return;
    }
    // cout << a[i] << endl;
    if (i < n && (st.find(b[i]) != st.end())){
        cout << n-i << endl;return;
    }
    int sm = m - tmp;
    int mx = *(--st.end());
    if (sm - mx + b[i] <= m){
        cout << n-i << endl;
    }else{
        cout << n-i+1 << endl;
    }

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