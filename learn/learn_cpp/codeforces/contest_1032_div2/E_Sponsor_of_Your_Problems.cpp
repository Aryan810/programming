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

int helper(int i, string & a, string & b, int bound){
    if (i >= a.size()){
        return 0;
    }
    int ret = 1e18;
    if (bound == 2){
        if (a[i] == b[i]){
            ret = 2 + helper(i+1, a, b, bound);
        }else if (abs(b[i]-a[i]) == 1){
            ret = min(ret, 1 + helper(i+1, a, b, 0));
            ret = min(ret, 1 + helper(i+1, a, b, 1));
        }else{
            ret = 0;
        }
    }else if (bound == 1){
        if (b[i] == '0'){
            ret = 1 + helper(i+1, a, b, bound);
        }else{
            ret = 0;
        }
    }else{
        if (a[i] == '9'){
            ret = 1 + helper(i+1, a, b, bound);
        }else{
            ret = 0;
        }
    }
    return ret;
}

void solve(){
    
    int l, r;
    cin >> l >> r;

    string a, b;
    a = to_string(l);
    b = to_string(r);

    int ans = helper(0, a, b, 2);
    cout << ans << endl;

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