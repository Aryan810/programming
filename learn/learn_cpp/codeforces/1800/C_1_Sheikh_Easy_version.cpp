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
    
    int n, q;
    cin >> n >> q;

    vi a(n);
    rep(i, n) cin >> a[i];
    vi cum(n+1, 0);
    for (int i=0;i<n;i++){
        cum[i+1] = cum[i] + a[i];
    }
    vi xcum(n+1, 0);
    for (int i=0;i<n;i++){
        xcum[i+1] = xcum[i] ^ a[i];
    }

    array<int, 3> ans = {(int)-1e18, -1, n};
    for (int i=0;i<q;i++){
        int L, R;
        cin >> L >> R;
        L--;
        R--;
        for (int j=L;j<=R;j++){
            int l = j;
            int h = R;
            int mxval = (cum[R+1]-cum[j]) - (xcum[R+1]^xcum[j]);
            // finding where this mxval first occurs.
            while (h-l > 1){
                int mid = (h + l)/2;
                if (cum[mid+1]-cum[j] - (xcum[mid+1]^xcum[j]) < mxval){
                    l = mid + 1;
                }else{
                    h = mid;
                }
            }
            // cout << j << " " << l << " " << h << " " << mxval << endl;
            if (cum[l+1]-cum[j] - (xcum[l+1]^xcum[j]) >= mxval){
                // cout << j << " . " << l << endl;
                if (ans[0] < mxval){
                    ans = {mxval, j, l};
                }else if (ans[0] == mxval){
                    if (abs(ans[1]-ans[2]) > abs(j-l)){
                        ans = {mxval, j, l};
                    }
                }
            }else{
                // cout << j << " " << h << endl;
                // cout << ans[0] << " . " << ans[1] << " . " << ans[2] << " " << mxval << endl;
                if (ans[0] < mxval){
                    ans = {mxval, j, h};
                }else if (ans[0] == mxval){
                    // cout << "here" << endl;
                    if (abs(ans[1]-ans[2]) > abs(j-h)){
                        ans = {mxval, j, h};
                    }
                }
            }
        }
    }

    cout << ans[1]+1 << " " << ans[2]+1 << endl;

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