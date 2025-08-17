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

bool qry(int a, int b, int c){
    a += 1;
    b += 1;
    c += 1;
    cout << "? " << a << " " << b << " " << c << endl;cout.flush();
    int res;
    cin >> res;
    return res;
}

void solve(){
    
    int n;
    cin >> n;

    int imp = -1;
    int crew = -1;
    int lst = -1;
    for (int i=0;i<=(n-3);i++){
        int res = qry(i, i+1, i+2);
        if (lst == -1){
            lst = res;
            continue;
        }
        if (lst == res){continue;}
        if (lst == 1 && res == 0){
            imp = i+2;
            crew = i-1;
        }else{
            imp = i-1;
            crew = i+2;
        }
        break;
    }
    // cout << imp << " " << crew << endl;
    vi out;
    out.push_back(imp);

    for (int i=0;i<n;i++){
        if (i == imp || i == crew){continue;}
        int res = qry(i, imp, crew);
        if (res == 0){
            out.push_back(i);
        }
    }

    cout << "! " << out.size() << " ";
    for (auto & ele: out){
        cout << ele+1 << " ";
    }cout << endl;cout.flush();

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