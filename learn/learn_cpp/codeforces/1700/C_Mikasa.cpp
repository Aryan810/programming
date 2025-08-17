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
int cnt = 0;
void solve(){
    
    int n, m;
    cin >> n >> m;
    if (m < n){
        cout << 0 << endl;return;
    }
    int mx = 0;
    if (m > 0){
        mx = log2(m);
    }
    int ans = 0;
    int tmp = 0;
    bool done = 0;
    mx += 1;
    // for (int i=mx;i>=0;i--){
    //     if (m&(1ll<<i)){
    //         cout << 1;
    //     }else{
    //         cout << 0;
    //     }
    // }cout << endl;
    // for (int i=mx;i>=0;i--){
    //     if (n&(1ll<<i)){
    //         cout << 1;
    //     }else{
    //         cout << 0;
    //     }
    // }cout << endl;
    int aft = 0;
    int foundzero = 0;
    for (int i=mx;i>=0;i--){
        int f = 0;
        int s = 0;
        int val = (1ll<<i);
        if (val&m){
            f = 1;
        }
        if (val&n){
            s = 1;
        }
        if (f){
            if (!s){
                ans += val;
                aft += val;
            }
        }else{
            foundzero = 1;
            if (s){
                done = 1;
                break;
            }else{
                tmp = val;
                aft = 0;
            }
        }
    }
    if (foundzero && !done){
        ans += tmp-aft;
    }
    if (!foundzero){
        ans += 1;
    }
    cout << ans << endl;

}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        cnt += 1;
        solve();
    }

    return 0;
}