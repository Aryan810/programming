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

#ifdef LOCAL
#include "/Users/aryangupta/Documents/programming/templets/algo/debug.h"
#else
#define debug(...) 42
#endif

void solve(){
    
    int n;
    cin >> n;

    vvi grid(n, vector<int>(n, -1));
    
    for (int i=0;i<n;i++){
        grid[i][i] = 0;
    }

    for (int i=0;i<n;i++){
        grid[i][0] = i;
        grid[0][i] = i;
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (grid[i][j] != -1){continue;}
            set<int> st;
            for (int l=i-1;l>=0;l--){
                st.insert(grid[l][j]);
            }
            for (int l=j-1;l>=0;l--){
                st.insert(grid[i][l]);
            }
            int mx = 0;
            for (auto & ele: st){
                if (ele == mx){
                    mx ++;
                }
            }
            grid[i][j] = mx;
        }   
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << grid[i][j] << " ";
        }cout << endl;
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