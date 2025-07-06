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

int dp[1001][1025];

void generateNext(int & n, int curr, int nxt, int j, vi & nexts){
    if (j >= n){
        nexts.push_back(nxt);
        return;
    }
    int x = ((int)(curr & (1ll << j)) != (int)0);
    int y = ((int)(curr & (1ll << (j+1)))  != (int)0);
    // cout << "X: " << x << " Y: " << y << endl;
    if (x == 1){
        generateNext(n, curr, nxt, j+1, nexts);
    }else{
        if (j+1 < n && y == 0){
            // cout << "HERE" << endl;
            generateNext(n, curr, nxt, j+2, nexts);
        }
        generateNext(n, curr, nxt + (1ll << j), j+1, nexts);
    }
}

int helper(int mask, int j, int & n, int & m){
    // cout << j << " " << mask << endl;
    if (j >= m){
        if (mask == 0){
            return 1;
        }else{
            return 0;
        }
    }
    if (dp[j][mask] != -1){
        return dp[j][mask];
    }

    vi nexts;
    generateNext(n, mask, 0, 0, nexts);

    int ret = 0;
    for (int i=0;i<nexts.size();i++){
        // cout << "i: " << i << " " << nexts[i] << endl;
        ret += helper(nexts[i], j+1, n, m);
        ret %= mod7;
    }

    return dp[j][mask] = ret;
}

void solve(){

    memset(dp, -1, sizeof(dp));
    
    int n, m;
    cin >> n >> m;
    cout << helper(0, 0, n, m) << endl;

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