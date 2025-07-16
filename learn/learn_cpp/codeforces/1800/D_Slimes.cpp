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
const int INF = 1e15;
void solve(){
    
    int n;
    cin >> n;

    vi a(n);
    rep(i, n) cin >> a[i];

    vi out(n, 1e18);
    vi cum(n+1, 0);
    cum[0] = 0;
    for (int i=0;i<n;i++){
        cum[i+1] = cum[i] + a[i];
    }

    vi pre(n), suf(n);
    int lst = -1;
    int ind = -1;
    for (int i=0;i<n;i++){
        if (a[i] == lst){
            pre[i] = ind;
        }else{
            pre[i] = i;
            lst = a[i];
            ind = i;
        }
    }

    lst = -1;
    ind = -1;

    for (int i=n-1;i>=0;i--){
        if (a[i] == lst){
            suf[i] = ind;
        }else{
            suf[i] = i;
            lst = a[i];
            ind = i;
        }
    }

    for (int i=0;i<n;i++){
        if ((i+1 < n && a[i+1] > a[i]) || (i-1>=0 && a[i-1] > a[i])){
            out[i] = 1;
            continue;
        }
        
        int ans = INF;
        // left side.
        if (i > 0 && (a[i-1] == a[i] && cum[i] > a[i])){
            auto it = lower_bound(all(cum), cum[i]-a[i]);
            if (it != cum.begin()){
                it--;
                int ind = it - cum.begin();
                ind = min(pre[i]-1, ind);
                if (ind >= 0){
                    ans = min(ans, i-ind);
                }
            }
        }else if (i > 1 && (a[i-2] == a[i-1] && cum[i] > a[i])){
            auto it = lower_bound(all(cum), cum[i]-a[i]);
            if (it != cum.begin()){
                it--;
                int ind = it - cum.begin();
                ind = min(pre[i-1]-1, ind);
                if (ind >= 0){
                    ans = min(ans, i-ind);
                }
            }
        }else if (i > 1 && (a[i-2] != a[i-1] && cum[i] > a[i])){
            auto it = lower_bound(all(cum), cum[i]-a[i]);
            if (it != cum.begin()){
                it--;
                int ind = it - cum.begin();
                ind = min(i-2, ind);
                if (ind >= 0){
                    ans = min(ans, i-ind);
                }
            }
        }

        // right side
        if (i+1 < n && (a[i+1] == a[i] && cum[n]-cum[i+1] > a[i])){
            auto it = upper_bound(all(cum), cum[i+1]+a[i]);
            if (it != cum.end()){
                int ind = it - cum.begin();
                ind = max(suf[i]+1, ind-1);
                if (ind < n){
                    ans = min(ans, ind-i);
                }
            }
        }else if (i+2 < n && (a[i+2] == a[i+1] && cum[n]-cum[i+1] > a[i])){
            auto it = upper_bound(all(cum), cum[i+1]+a[i]);
            if (it != cum.end()){
                int ind = it - cum.begin();
                ind = max(suf[i+1]+1, ind-1);
                if (ind < n){
                    ans = min(ans, ind-i);
                }
            }
        }else if (i+2 < n && (a[i+2] != a[i+1] && cum[n]-cum[i+1] > a[i])){
            // cout << i << " " << " here" << endl;
            auto it = upper_bound(all(cum), cum[i+1]+a[i]);
            if (it != cum.end()){
            
                int ind = it - cum.begin();
                // cout << ind << " " << i+2 << endl;
                ind = max(i+2, ind-1);
                if (ind < n){
                    ans = min(ans, ind-i);
                }
            }
        }

        if (ans == INF){
            out[i] = -1;
        }else{
            out[i] = ans;
        }

    }

    for (auto & ele: out){
        cout << ele << " ";
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