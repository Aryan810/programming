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
    
    int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];
    if (n == 1){
        for (int i=0;i<m;i++){
            int p, q;
            cin >> q >> q;
            cout << 1 << endl;
        }
        return;
    }
    int ans = 0;
    int lst = -1;
    for (int i=n-1;i>=0;i--){
        if (a[i] == lst){
            ans += (i+1);
        }else{
            ans += (i+1)*(n-i);
        }
        lst = a[i];
    }
    for (int i=0;i<m;i++){
        int ind, x;
        cin >> ind >> x;
        int b1=0, b2=0, a1=0, a2=0;
        if (ind == 1){
            if (a[0] == a[1]){
                b1 = 1;
            }else{
                b1 = n;
            }
            a[ind-1] = x;
            if (a[0] == a[1]){
                a1 = 1;
            }else{
                a1 = n;
            }
            ans += a1 - b1;
        }else if (ind == n){
            if (a[n-2] == a[n-1]){
                b2 = 1;
            }else{
                b2 = 2;
            }
            a[ind-1] = x;
            if (a[n-2]==a[n-1]){
                a2 = 1;
            }else{
                a2 = 2;
            }
            ans += (a2 - b2)*(n-1);
        }else{
            ind -= 1;
            if (a[ind] == a[ind+1]){
                b1 = 1;
            }else{
                b1 = (n-ind);
            }
            if (a[ind] == a[ind-1]){
                b2 = 1;
            }else{
                b2 = (n-ind+1);
            }
            a[ind] = x;
            if (a[ind] == a[ind+1]){
                a1 = 1;
            }else{
                a1 = (n-ind);
            }
            if (a[ind] == a[ind-1]){
                a2 = 1;
            }else{
                a2 = (n-ind+1);
            }
            ans += (a1-b1)*(ind + 1) + (a2-b2) * (ind);
        }
        cout << ans << endl;
    }

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