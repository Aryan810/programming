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
int dp[20][10][4][2];

int helper(int n, int prev, int tight, int lz, string & a, string & b){
    // cout << n << " " << prev << " " << tight << " " << lz << endl;
    if (n >= 20){
        return 1;
    }
    if (dp[n][prev][tight][lz] != -1){
        return dp[n][prev][tight][lz];
    }
    int ret = 0;

    if (tight == 3){ // tight with both 'a' and 'b'.
        int mn = a[n]-'0';
        int mx = b[n]-'0';
        if (mx-mn == 0){
            if (mn != prev || lz){
                if (lz && mn == 0){
                    ret += helper(n+1, mn, tight, lz, a, b);
                }else{
                    ret += helper(n+1, mn, tight, 0, a, b);
                }
            }
        }else if (mx-mn == 1){
            if (mx != prev){ret += helper(n+1, mx, 2, 1, a, b);}
            if (mn != prev || lz){
                if (lz && mn == 0){
                    ret += helper(n+1, mn, 1, lz, a, b);
                }else{
                    ret += helper(n+1, mn, 1, 0, a, b);
                }
            }
        }else{
            if (mx != prev){ret += helper(n+1, mx, 2, 1, a, b);}
            if (mn != prev || lz){
                if (lz && mn == 0){
                    ret += helper(n+1, mn, 1, lz, a, b);
                }else{
                    ret += helper(n+1, mn, 1, 0, a, b);
                }
            }
            for (int l=mn+1;l<mx;l++){
                if (l != prev){ret += helper(n+1, l, 0, 0, a, b);}
            }
        }
    }else if (tight == 2){
        int mx = b[n]-'0';
        int mn = 0;
        if (mx == mn){
            if (mx != prev){ret += helper(n+1, mx, tight, 0, a, b);}
        }else{
            if (mx != prev){ret += helper(n+1, mx, tight, 0, a, b);}
            for (int l=mn;l<mx;l++){
                if (l != prev){ret += helper(n+1, l, 0, 0, a, b);}
            }
        }
    }else if (tight == 1){
        int mn = a[n]-'0';
        int mx = 9;
        if (mx == mn){
            if (mx != prev || lz){
                if (lz && mx == 0){
                    ret += helper(n+1, mx, tight, lz, a, b);
                }else{
                    ret += helper(n+1, mx, tight, 0, a, b);
                }
            }
        }else{
            if (mn != prev || lz){
                if (lz && mn == 0){
                    ret += helper(n+1, mn, tight, lz, a, b);
                }else{
                    ret += helper(n+1, mn, tight, 0, a, b);
                }
            }
            for (int l=mn+1;l<=mx;l++){
                if (l != prev){ret += helper(n+1, l, 0, 0, a, b);}
            }
        }
    }else{
        int mn = 0;
        int mx = 9;
        for (int l=mn;l<=mx;l++){
            if (l != prev){
                ret += helper(n+1, l, 0, 0, a, b);
            }
        }
    }
    return dp[n][prev][tight][lz] = ret;

}

void solve(){
    
    int ta, tb;
    cin >> ta >> tb;
    string a = to_string(ta);
    string b = to_string(tb);
    memset(dp, -1, sizeof(dp));
    while (a.size() < 20){
        a.insert(a.begin(), '0');
    }
    while (b.size() < 20){
        b.insert(b.begin(), '0');
    }
    // cout << a << endl << b << endl;
    cout << helper(0, 0, 3, 1, a, b) << endl;

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