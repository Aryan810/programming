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
    
    int n;
    cin >> n;

    vi a(n);
    int mx = 0;
    int i = 0;
    int sm = 0;
    rep(l, n){
        int x;
        cin >> x;
        if (mx < x){
            mx = x;
            i = l;
        }
        sm += x;
        a[l] = x;
    }

    // cout << i << " " << j << endl;
    // int ans = 0;

    if (mx > 2*(sm - mx)){
        cout << sm - mx << endl;
    }else{
        cout << sm/3 << endl;
    }

    // while (a[j] > 0){
    //     if (a[i] == 0){
    //         while (a[i] == 0){
    //             i = (i + 1)%n;
    //         }
    //         j = i + 1;
    //         j %= n;
    //         if (a[j] == 0){break;}
    //     }
    //     if (a[i] == a[j] && a[i] == 1){
    //         int nxt = (j+1)%n;
    //         if (a[nxt] > 0){
    //             a[nxt] -= 1;
    //             a[i] = 0;
    //             a[j] = 0;
    //             ans += 1;
    //             i = nxt;
    //             j = i + 1;
    //         }
    //         continue;
    //     }else if (a[i] == 1){
    //         a[j] -= 2;
    //         a[i] -= 1;
    //         i += 1;
    //         j += 1;
    //         ans += 1;
    //         continue;
    //     }
    //     i %= n;
    //     j %= n;
    //     int f = a[i];
    //     int s = a[j];
    //     if (f > 2*s){
    //         ans += s;
    //         a[i] -= 2*s;
    //         a[j] = 0;
    //         j += 1;
    //     }else if (f == 2*s){
    //         ans += s;
    //         a[i] = 0;
    //         a[j] = 0;
    //         j += 1;
    //         i += 1;
    //     }else if ((f+1)&1){
    //         ans += f/2;
    //         a[i] = 0;
    //         a[j] -= f/2;
    //         i += 1;
    //         j += 1;
    //     }else if (f&1){
    //         ans += f/2;
    //         a[i] = 1;
    //         a[j] -= f/2;
    //     }
    //     i %= n;
    //     j %= n;
    // }
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