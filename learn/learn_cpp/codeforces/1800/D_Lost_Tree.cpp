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
#define ff first
#define ss second
#define umap(x, y) unordered_map<x, y, custom_hash>
const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){
    
    int n;
    cin >> n;

    set<int> lft;
    for (int i=1;i<=n;i++){
        lft.insert(i);
    }
    set<pi> out;
    
    // taking 1 as root.
    
    cout << "? " << 1 << endl;cout.flush();
    vi a(n);
    map<int, vi> levele;
    rep(i, n){
        int x;
        cin >> x;
        if (x == 1){
            out.insert({min(i+1, 1ll), max(i+1, 1ll)});
        }
        levele[x].push_back(i+1);
    }
    vi odd;
    vi even;
    for (int i=1;levele[i].size() > 0;i++){
        if (i&1){
            for (auto & ele: levele[i]){
                odd.push_back(ele);
            }
        }else{
           for (auto & ele: levele[i]){
                even.push_back(ele);
            } 
        }
    }
    if (odd.size()+1 <= (n+1)/2){
        for (auto & ele: odd){
            cout << "? " << ele << endl;cout.flush();
            for (int i=0;i<n;i++){
                int x;
                cin >> x;
                if (x == 1){
                    out.insert({min(ele, i+1), max(ele, i+1)});
                }
            }
        }
    }else{
        for (auto & ele: even){
            cout << "? " << ele << endl;cout.flush();
            for (int i=0;i<n;i++){
                int x;
                cin >> x;
                if (x == 1){
                    out.insert({min(ele, i+1), max(ele, i+1)});
                }
            }
        }
    }
    cout << "! " << endl;cout.flush();
    for (auto & ele: out){
        cout << ele.first << " " << ele.second << endl;cout.flush();
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