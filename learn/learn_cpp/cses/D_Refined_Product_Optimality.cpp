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
int binexpiter(int a, int b){
    a %= M;
    b %= M;
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
    
    int n, q;
    cin >> n >> q;

    vi a(n);
    ordered_set<pi> sa;
    rep(i, n){
        int x;
        cin >> x;
        sa.insert({x, i});
        a[i] = x;
    }

    vi b(n);
    ordered_set<pi> sb;
    rep(i, n){
        int x;
        cin >> x;
        sb.insert({x, i});
        b[i] = x;
    }

    int ans = 1;
    for (int i=0;i<n;i++){
        auto ca = sa.find_by_order(i);
        auto cb = sb.find_by_order(i);
        ans *= min(ca->first, cb->first);
        ans %= M;
    }

    cout << ans << " ";
    for (int j=0;j<q;j++){
        int t;
        cin >> t;
        int x;
        cin >> x;
        if (t == 1){
            int f = sa.order_of_key({a[x-1], x-1});
            auto fb = sb.find_by_order(f);
            if (f+1 == n){
                ans *= binexpiter(min(fb->first, a[x-1]), M-2);
                ans %= M;
                sa.erase({a[x-1], x-1});
                a[x-1] += 1;
                ans *= min(fb->first, a[x-1])%M;
                ans %= M;
                sa.insert({a[x-1], x-1});
            }else{
                auto nxt = sa.order_of_key(*(--sa.upper_bound({a[x-1], 1e18})));
                if (nxt == f){
                    ans *= binexpiter(min(fb->first, a[x-1]), M-2);
                    ans %= M;
                    sa.erase({a[x-1], x-1});
                    a[x-1] += 1;
                    ans *= min(fb->first, a[x-1])%M;
                    ans %= M;
                    sa.insert({a[x-1], x-1});
                }else{
                    auto nxtb = sb.find_by_order(nxt);
                    ans *= binexpiter(min(nxtb->first, a[x-1]), M-2);
                    ans %= M;
                    sa.erase({a[x-1], x-1});
                    a[x-1] += 1;
                    ans *= min(nxtb->first, a[x-1])%M;
                    ans %= M;
                    sa.insert({a[x-1], x-1});
                }
            }
        }else{
            int f = sb.order_of_key({b[x-1], x-1});
            auto fa = sa.find_by_order(f);
            if (f+1 == n){
                ans *= binexpiter(min(fa->first, b[x-1]), M-2);
                ans %= M;                
                sb.erase({b[x-1], x-1});
                b[x-1] += 1;
                ans *= min(fa->first, b[x-1])%M;
                ans %= M;
                sb.insert({b[x-1], x-1});
            }else{
                auto nxt = sb.order_of_key(*(--sb.upper_bound({b[x-1], 1e18})));
                if (nxt == f){
                    ans *= binexpiter(min(fa->first, b[x-1]), M-2);
                    ans %= M;
                    sb.erase({b[x-1], x-1});
                    b[x-1] += 1;
                    ans *= min(fa->first, b[x-1])%M;
                    ans %= M;
                    sb.insert({b[x-1], x-1});
                }else{
                    auto nxta = sa.find_by_order(nxt);
                    ans *= binexpiter(min(nxta->first, b[x-1]), M-2);
                    sb.erase({b[x-1], x-1});
                    b[x-1] += 1;
                    ans *= min(nxta->first, b[x-1])%M;
                    ans %= M;
                    sb.insert({b[x-1], x-1});
                }
            }
        }
        cout << ans << " ";
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