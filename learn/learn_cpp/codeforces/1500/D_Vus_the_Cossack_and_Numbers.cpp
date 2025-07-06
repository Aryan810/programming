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
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> nor(n, 0);
    vector<int> neg(n, 0);
    int sm = 0;

    rep(i, n){
        double d;
        cin >> d;
        if (d < 0){a[i] = (int)ceil(d);}else{
            a[i] = (int)d;
        }
        sm += a[i];
        if (d-(int)d == 0.0){
            nor[i] = 1;
        }
        if (!nor[i]){
            if (d < 0){
                neg[i] = 1;
            }else{
                neg[i] = 0;
            }
        }
    }

    if (sm == 0){
        for (auto & ele: a){
            cout << ele << endl;
        }
        return;
    }
    for (int i=0;i<n;i++){
        if (sm == 0){break;}
        if (!nor[i] && !neg[i]){
            if (sm < 0){
                a[i] += 1;
                sm += 1;
            }
        }else if (!nor[i] && neg[i]){
            if (sm > 0){
                a[i] -= 1;
                sm -= 1;
            }
        }
    }
    for (auto & ele: a){
        cout << ele << endl;
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