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
    
    int p1, p2, p3, p4;
    cin >> p1 >> p2 >> p3 >> p4;
    int ans = 0;
    while ((p1 + p2 + p3 + p4) > 0){
        if (p4&1){
            p4 -= 1;
        }
        int b1 = (p1+p3)&1;
        int b2 = (p2+p3)&1;
        if (b1 && b2){
            if (p3 != 0){
                p3 -= 1;
            }else{
                p1 -= 1;
                p2 -= 1;
            }
        }else if (b1){
            if (p1 != 0){
                p1 -= 1;
            }else{
                p2 -= 1;
                p3 -= 1;
            }
        }else if (b2){
            if (p2 != 0){
                p2 -= 1;
            }else{
                p1 -= 1;
                p3 -= 1;
            }
        }
        ans += 1;
        if (p4 > 0){
            p4 -= 1;
        }else{
            if (p3 > 0){
                p3 -= 1;
            }else{
                if (p2 > 0){
                    p2 -= 1;
                }else{
                    p1 -= 1;
                }
            }
        }
    }

    ans = max(ans-1, 0ll);

    // // now all are even, so we can start.
    // cout << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
    // // first all p4
    // int ans = 1;
    // ans += (p4)/2;

    // if ((p3) & 1){
    //     int tmp = 0;
    //     if (p3 > 1){tmp += (p3 + 1)/2;}
    //     if (p1 > 1){tmp += (p1 + 1)/2;}
    //     if (p2 > 1){tmp += (p2 + 1)/2;}
    //     if (tmp != 0){
    //         tmp -= 1;
    //     }
    //     ans += tmp;
    // }else{
    //     int tmp = 0;
    //     if (p3 > 0){tmp += (p3 + 2)/2;}
    //     if (p1 > 0){tmp += (p1 + 2)/2;}
    //     if (p2 > 0){tmp += (p2 + 2)/2;}
    //     if (tmp != 0){
    //         tmp -= 1;
    //     }
    //     ans += tmp;
    // }

    cout << ans << endl;


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