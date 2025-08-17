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
int n;
bool poss = 0;
vi a;

void helper(int i, int sm, bool & poss, int val, vector<int> & b){
    if (i >= b.size()){
        if (sm == val){
            poss = 1;
        }
        return;
    }

    // taking this element.
    helper(i+1, sm + b[i], poss, val, b);

    // not taking
    helper(i+1, sm, poss, val, b);

    // decreasing by it.
    helper(i+1, sm-b[i], poss, val, b);
}

void solve(){
    
    cin >> n;
    a.resize(n);
    rep(i, n){
        int x;
        cin >> x;
        a[i] = abs(x);
    }
    sort(all(a));
    bool poss = 0;
    for (int i=0;i<n;i++){
        vi b;
        for (int j=0;j<n;j++){
            if (j != i){
                b.push_back(abs(a[j]));
            }
        }
        helper(0, 0, poss, a[i], b);
        if (poss){
            break;
        }
    }

    cout << (poss?"YES":"NO") << endl;
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