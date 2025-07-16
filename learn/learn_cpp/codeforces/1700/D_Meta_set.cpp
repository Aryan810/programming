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

void solve(){
    
    int n, k;
    cin >> n >> k;

    vector<int> v(n, 0);

    vector<vector<int> > a(n, vector<int>(k));
    for (int i=0;i<n;i++){
        for (int j=0;j<k;j++){
            cin >> a[i][j];
        }
    }
    sort(all(a));
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            vector<int> tmp(k);
            auto & f = a[i];
            auto & s = a[j];
            for (int l=0;l<k;l++){
                if (f[l] == s[l]){
                    tmp[l] = f[l];
                }else{
                    tmp[l] = 3 - (f[l] + s[l]);
                }
            }
            
            auto it = lower_bound(a.begin() + j + 1, a.end(), tmp);
            if (it != a.end() && *it == tmp){
                v[i] += 1;
                v[j] += 1;
                v[it-a.begin()] += 1;
            }
        }
    }
    int ans = 0;
    for (int i=0;i<n;i++){
        ans += (v[i]*(v[i] - 1))/2;
    }
    cout << ans << endl;



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