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
const int M = 998244353;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = (ans * a)%M;
        }
        a = (a * a)%M;
        b >>= 1;
    }
    return ans;
}

void solve(){
    
    int n;
    cin >> n;

    vi a(n);
    rep(i, n) cin >> a[i];
    vi cum(n+1);
    cum[0] = 0;
    int sm = 0;
    ordered_multiset<int> st;
    for (int i=0;i<n;i++){
        sm += a[i];
        cum[i+1] = sm;
        st.insert(sm);
    }
    int mxk = -1e17;
    vi val(n, -1e17);
    sm = 0;
    for (int i=0;i<n;i++){
        sm += a[i];
        if (sm < 0){
            val[i] = max(val[i], abs(sm) + cum[n]-cum[i+1]);
            mxk = max(val[i], mxk);
        }
    }
    mxk = max(mxk, sm);
    int ans = 0;
    sm = 0;
    int pos = 0;
    for (int i=0;i<n;i++){
        sm += a[i];
        int ord = st.order_of_key(sm);
        if (ord < st.size()){
            st.erase(st.find_by_order(ord));
        }
        
        if (sm < 0 && val[i]==mxk){
            int tmp = 0;
            int extra = 2*abs(sm);
            auto it = st.upper_bound(-1*extra);
            int num = st.size() - st.order_of_key(*it);
            tmp += binexpiter(2, pos+num);
            tmp %= M;
            ans = (ans + tmp)%M;
            // cout << i << " " << tmp << " " << num << " " << pos << endl;
        }
        if (sm >= 0){
            pos += 1;
        }
    }
    if (ans == 0){
        cout << binexpiter(2, n) << endl;
    }else{
        cout << ans << endl;
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