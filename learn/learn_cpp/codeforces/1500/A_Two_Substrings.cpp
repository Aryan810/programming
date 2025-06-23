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
const int N = 1e5 + 1;
int dp[N][4];

int helper(int i, int state, string & s, int & n){
    if (i >= n || state == 3){
        if (state == 3){
            return 1;
        }else{
            return 0;
        }
    }

    if (dp[i][state] != -1){
        return dp[i][state];
    }

    int ret = 0;
    if (i+1 < n){
        if (s.substr(i, 2) == "AB"){
            if (state == 0){
                ret = max(ret, helper(i+2, 1, s, n));
                ret = max(ret, helper(i+1, 0, s, n));
            }else if (state == 1){
                ret = max(ret, helper(i+1, 1, s, n));
            }else if (state == 2){
                ret = max(ret, 1ll);
            }
        }else if (s.substr(i, 2) == "BA"){
            if (state == 0){
                ret = max(ret, helper(i+2, 2, s, n));
                ret = max(ret, helper(i+1, 0, s, n));
            }else if (state == 1){
                ret = max(ret, 1ll);
            }else if (state == 2){
                ret = max(ret, helper(i+1, 2, s, n));
            }
        }else{
            ret = max(ret, helper(i+1, state, s, n));
        }
    }
    return dp[i][state] = ret;
}

void solve(){
    
    string s;
    cin >> s;
    int ab = 0, ba = 0;
    int n = s.size();
    memset(dp, -1, sizeof(dp));
    int ans = helper(0, 0, s, n);
    cout << (ans?"YES":"NO") << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    solve();

    return 0;
}