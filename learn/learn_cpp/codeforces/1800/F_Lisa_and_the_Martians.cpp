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

array<int, 3> ans; 
int k;
vi a;
int calc(int i, int j){
    int ret = 0;
    // cout << a[i] << " <-> " << a[j] << " " << k << endl;
    for (int b=0;b<k;b++){
        int f = 0;
        int s = 0;
        if ((1ll<<b)&a[i]){f = 1;}
        if ((1ll<<b)&a[j]){s = 1;}
        // cout << "F: " << f << " " << "S: " << s << endl;
        if ((f & s) || (!f && !s)){
            ret += (1ll<<b);
        }
    }
    return ret;
}

void helper(int i, vi & tmp){

    if (tmp.size() == 2 || i < 0){
        int val = calc(tmp[0], tmp[1]);
        if (ans[0] < val){
            ans = {val, tmp[0], tmp[1]};
        }
        return;
    }

    vi one;
    vi zero;
    for (auto & ele: tmp){
        if ((1ll<<i)&a[ele]){
            one.push_back(ele);
        }else{
            zero.push_back(ele);
        }
    }

    if (one.size() >= 2 && zero.size() >= 2){
        helper(i-1, one);
        helper(i-1, zero);
    }else if (one.size() >= 2){
        helper(i-1, one);
    }else if (zero.size() >= 2){
        helper(i-1, zero);
    }
}

void solve(){
    
    int n;
    cin >> n >> k;
    ans = {0, 0, 1};
    a.clear();
    a.resize(n);
    rep(i, n) cin >> a[i];
    vi tmp(n);
    for (int i=0;i<n;i++){
        tmp[i] = i;
    }

    helper(k-1, tmp);
    int f = a[ans[1]];
    int x = 0;
    for (int i=0;i<k;i++){
        if ((int)(f&(1ll<<i)) == 0){
            x += (1ll<<i);
        }
    }
    cout << ans[1]+1 << " " << ans[2]+1 << " " << x << endl;

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