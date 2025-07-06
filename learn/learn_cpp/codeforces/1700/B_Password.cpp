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
const int M = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = (ans * a)%M;
        }
        a = (a * a)%M;
        b >>= 1;
    }
    return ans;
}

bool check(int mid, vi & invs, vi & dp, vi & mlen){
    if (mid <= 0){
        return 1;
    }

    int len = mlen[mid-1];
    int phs = (dp[len]-dp[0]+M)%M;
    int n = dp.size()-1;
    for (int i=1;i<(n-len);i++){
        int chs = (dp[i+len] - dp[i] + M)%M;
        chs *= invs[i];
        chs %= M;
        // cout << i << " " << chs << endl;

        if (phs == chs){
            return 1;
        }
    }
    return 0;
}

void solve(){
    
    string s;
    vector<vector<int> > ind(26);
    cin >> s;
    int n = s.size();

    vector<int> dp(n+1, 0);
    int p = 31;
    dp[0] = 0;
    int pow = 1;
    int inv = binexpiter(p, M-2);
    int cinv = inv;
    vector<int> invs(n+1, 1);
    for (int i=1;i<=n;i++){
        dp[i] = dp[i-1] + (s[i-1]-'a')*pow;
        dp[i] %= M;
        invs[i] = cinv;
        cinv *= inv;
        cinv %= M;
        pow *= p;
        pow %= M;
    }

    vector<int> mlen;
    for (int i=0;i<n-1;i++){
        int phs = (dp[i+1]-dp[0]+M)%M;
        int shs = (dp[n] - dp[n-i-1]+M)%M;
        shs *= invs[n-i-1];
        shs %= M;
        // cout << i+1 << " " << phs << " " << shs << endl;
        if (phs == shs){
            mlen.push_back(i+1);
        }
    }

    int l = 0;
    int h = mlen.size();

    while (h - l > 1){
        int mid = (h+l)/2;
        if (check(mid, invs, dp, mlen)){
            l = mid;
        }else{
            h = mid - 1;
        }
    }
    // for (auto & ele: mlen){
    //     cout << ele << " ";
    // }cout << endl;
    // cout << l << " " << h << endl;
    if (check(h, invs, dp, mlen)){
        if (h == 0){
            cout << "Just a legend" << endl;return;
        }
        for (int i=0;i<mlen[h-1];i++){
            cout << s[i];
        }cout << endl;
    }else{
        if (l == 0){
            cout << "Just a legend" << endl;return;
        }
        for (int i=0;i<mlen[l-1];i++){
            cout << s[i];
        }cout << endl;
    }


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