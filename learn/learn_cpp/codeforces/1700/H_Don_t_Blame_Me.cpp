// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>
const int M = 1e9 + 7;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

int helper(int i, int val, vector<vector<int> > & dp, int k, vi & a){
    if (i >= dp.size()){
        if (val == 127){
            return 0;
        }
        int sets = 0;
        for (int i=0;i<=6;i++){
            if ((1 << i)&val){
                sets += 1;
            }
        }
        if (sets == k){
            return 1;
        }else{
            return 0;
        }
    }
    if (dp[i][val] != -1){
        return dp[i][val];
    }
    int ret = 0;
    ret += helper(i+1, val&a[i], dp, k, a);
    ret += helper(i+1, val, dp, k, a);
    ret %= M;
    return dp[i][val] = ret;
}

void solve(){
    
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];

    vector<vector<int> > dp(n, vector<int>(128, -1));
    cout << helper(0, 127, dp, k, a) << endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}