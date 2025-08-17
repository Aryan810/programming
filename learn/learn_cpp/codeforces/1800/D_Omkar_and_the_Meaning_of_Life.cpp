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
int qry(vi & a){
    int n = a.size();
    cout << "? ";
    for (int i=0;i<n;i++){
        cout << a[i] << " ";
    }cout << endl;cout.flush();
    int res;
    cin >> res;
    return res;
}
void solve(){
    
    int n;
    cin >> n;

    int curr = 1;
    vi out(n, -1);
    vi nxt(n+1, -1);
    vi prev(n+1, -1);
    int ind = 0;

    for (int i=0;i<n;i++){
        vi ar(n, 2);
        ar[i] = 1;
        int bk = qry(ar);
        ar.assign(n, 1);
        ar[i] = 2;
        int fo = qry(ar);
        if (bk == 0){
            ind = i;
        }
        // cout << i << " " << bk << " " << fo << endl;
        if (bk != 0 && bk-1 != i){
            nxt[bk-1] = i;
        }
        if (fo != 0 && fo-1 != i){
            nxt[i] = fo-1;
        }
    }
  
    // cout << ind << endl;
    while (ind != -1){
        out[ind] = curr;
        ind = nxt[ind];
        curr += 1;
    }
    // 1 1 2 2 1 2 4 1 2 0 0 4
    cout << "! ";
    for (auto & ele: out){
        cout << ele << " ";
    }cout << endl;cout.flush();

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