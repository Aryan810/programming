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

void solve(){
    
    string s;
    cin >> s;
    if (s.find("0") < s.size()){
        cout << "YES" << endl << "0" << endl;return;
    }
    for (int i=8;i<1000;i+=8){
        string req = to_string(i);
        int f = 0;
        int l = 0;
        // cout << i << " " << req << endl;
        while (l < req.size() && f < s.size()){
            if (s[f] == req[l]){
                f += 1;
                l += 1;
            }else{
                f += 1;
            }
        }
        // cout << l << " " << req << endl;
        if (l >= req.size()){
            cout << "YES" << endl;
            cout << req << endl;return;
        }
    }
    cout << "NO" << endl;

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