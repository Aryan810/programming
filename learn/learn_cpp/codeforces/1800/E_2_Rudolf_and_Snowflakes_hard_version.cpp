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
const int M = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}
bool check(int k, int p, int n){
    int v1 = 0;
    int val = 1;
    bool overflow = 0;
    for (int i=0;i<=p;i++){
        if (v1 > 1e18 - val){
            overflow = 1;
            break;
        }
        v1 += val;
        if (val > (int)(1e18 + k - 1)/k){
            if (i != p){
                overflow = 1;
                
            }
            break;
        }else{
            val *= k;
        }
    }

    return (!overflow && v1 == n);
    
}

void solve(){
    
    int n;
    cin >> n;

    // iterate for values of maxpower.
    for (int p=2;p<60;p++){
        // if ((1ll<<(p+1))-1 > n){
        //     cout << "NO" << endl;return;
        // }

        int l = 2;
        int h = binexpiter(10, (18 + p + 1)/p);
        while (h - l > 1){
            int k = (h + l)/2;
            int v1 = 0;
            int val = 1;
            bool overflow = 0;
            for (int i=0;i<=p;i++){
                if (v1 > 1e18 - val){
                    overflow = 1;
                    break;
                }
                v1 += val;
                if (val > (int)(1e18 + k - 1)/k){
                    if (i != p){
                        overflow = 1;
                        
                    }
                    break;
                }else{
                    val *= k;
                }
            }
            // cout << v1 << " " << n << endl;
            // cout << l << " " << k << " " << h << endl;
            if (overflow){
                h = k;
            }else if (v1 < n){
                l = k;
            }else{
                h = k;
            }
        }

        if (check(h, p, n) || check(l, p, n)){
            cout << "YES" << endl;return;
        }   
        
    }
    cout << "NO" << endl;return;

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