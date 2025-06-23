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
const int SZ = 1e5 + 1;
int dp[SZ][101];

int helper(int i, int last, vi & a, int & m){
    // cout << i << " " << last << " " << dp[i][last] << endl;
    if (i == a.size() - 1){
        if (a[i] != 0){
            if (abs(last-a[i]) <= 1){
                return 1;
            }else{
                return 0;
            }
        }else{
            int ret = 1;
            if (last + 1 <= m){ret += 1;}
            if (last-1 > 0){ret += 1;}
            return ret;
        }
    }
    if (dp[i][last] != -1){
        return dp[i][last];
    }

    int ret = 0;
    if (i == 0){
        if (a[i] != 0){
            ret += helper(i+1, a[i], a, m);
        }else{
            for (int j=1;j<=m;j++){
                ret += helper(i+1, j, a, m);
            }
        }
    }else{
        if (a[i] != 0){
            if (abs(a[i]-last) <= 1){
                ret += helper(i+1, a[i], a, m);
            }
        }else{
            if (last + 1 <= m){ret += helper(i+1, last+1, a, m);}
                if (last-1 > 0){ret += helper(i+1, last-1, a, m);}
            ret += helper(i+1, last, a, m);
        }
    }
    ret %= M;
    return dp[i][last] = ret;
}

void solve(){
    
    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));

    vi a(n);
    rep(i, n) cin >> a[i];
    if (n == 1){
        if (a[0] == 0){
            cout << m << endl;
        }else{
            cout << 1 << endl;
        }
        return;
    }
    int ans = helper(0, 1, a, m);
    cout << ans << endl;
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test = 1;

    while(test--){
        solve();
    }

    return 0;
}