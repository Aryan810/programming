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
    
    int n;
    cin >> n;

    vector<pi> a(n);
    vector<array<int, 3> > x(n);
    vector<array<int, 3> > y(n);
    for (int i=0;i<n;i++){
        int u, v;
        cin >> u >> v;
        a[i] = {u, v};
        x[i] = {u, v, i};
        y[i] = {v, u, i};
    }

    sort(all(x));
    sort(all(y));

    set<int> done;
    vector<pi> out;
    vector<int> xlyl, xlyr, xryr, xryl;

    for (int i=0;i<(n/2);i++){
        auto curr = y[i];
        array<int, 3> tmp = {curr[1], curr[0], curr[2]};
        auto it = lower_bound(all(x), tmp);
        if (it != x.end() && (*it == tmp && it-x.begin() < n/2)){
            xlyl.push_back(tmp[2]);
        }else{
            xryl.push_back(tmp[2]);
        }
    }

    for (int i=n/2;i<n;i++){
        auto curr = y[i];
        array<int, 3> tmp = {curr[1], curr[0], curr[2]};
        auto it = lower_bound(all(x), tmp);
        if (it != x.end() && (*it == tmp && it-x.begin() >= n/2)){
            xryr.push_back(tmp[2]);
        }else{
            xlyr.push_back(tmp[2]);
        }
    }
    // cout << xlyl.size() << " " << xlyr.size() << " " << xryr.size() << " " << xryl.size() << endl;
    int curr = 0;
    while (xlyl.size() > 0 && xryr.size() > 0){
        out.push_back({xlyl.back(), xryr.back()});
        xlyl.pop_back();
        xryr.pop_back();
    }
    while (xlyr.size() > 0 && xryl.size() > 0){
        out.push_back({xlyr.back(), xryl.back()});
        xlyr.pop_back();
        xryl.pop_back();
    }
    

    for (auto & ele: out){
        cout << ele.first+1 << " " << ele.second+1 << endl;
    }

    


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