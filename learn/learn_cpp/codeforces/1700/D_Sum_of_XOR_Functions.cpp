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
const int M = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){
    int n;
    cin >> n;

    vi a(n);
    rep(i, n) cin >> a[i];
    int ans = 0;
    for (int b=0;b<32;b++){
        vector<int> cum(n+1, 0);
        vector<int> evn(n+2, 0);
        vector<int> odd(n+2, 0);
        cum[0] = 0;
        evn[0] = 0;
        odd[0] = 0;
        int sm = 0;
        int es = 0;
        int os = 0;
        for (int i=0;i<n;i++){
            if ((1ll<<b)&a[i]){
                sm += 1;
            }
            cum[i+1] = sm;
        }

        for (int i=0;i<=n;i++){
            if (cum[i]&1){
                os += 1;
            }else{
                es += 1;
            }
            evn[i+1] = es;
            odd[i+1] = os;
        }

        // each(ele, cum){
        //     cout << ele << " ";
        // }cout << endl;
        // each(ele, evn){
        //     cout << ele << " ";
        // }cout << endl;
        // each(ele, odd){
        //     cout << ele << " ";
        // }cout << endl;
        int temp = 0;
        // calculating f * r
        for (int i=0;i<n;i++){
            if (cum[i+1]&1){
                temp += (i+1)*(evn[i+2]);
            }else{
                temp += (i+1)*(odd[i+2]);
            }
            temp %= M;
        } 
        // calculating -1*(f * l)
        for (int i=0;i<n;i++){
            if (cum[i]&1){
                temp -= (i+1)*(evn[n+1]-evn[i+1]);
            }else{
                temp -= (i+1)*(odd[n+1]-odd[i+1]);
            }
            temp %= M;
        } 

        // calculating sum of f
        for (int i=0;i<n;i++){
            if (cum[i]&1){
                temp += (evn[n+1]-evn[i+1]);
            }else{
                temp += (odd[n+1]-odd[i+1]);
            }
            temp %= M;
        }
        // cout << b << " " << temp << endl;
        ans += (1ll<<b)*temp;
        ans %= M;
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