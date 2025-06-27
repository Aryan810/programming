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
    
    int n, m;
    cin >> n >> m;
    int p = 1ll << n;
    vi a(p);
    rep(i, p) cin >> a[i];
    vector<int> graph(2*p);

    // calculate
    for (int i=0;i<p;i++){
        graph[i+1] = a[i]; 
    }

    for (int i=(p+1);i<graph.size();i++){
        int h = 0;
        int tmp = i;
        while (1){
            if (tmp-(1ll<<(n-h)) <= 0){break;}else{
                tmp -= (1ll<<(n-h));
                h += 1;
            }
        }
        int f = i - tmp + 1 - 2*(1ll << (n-h));
        int c2 = f + 2*tmp - 1;
        int c1 = c2 - 1;
        if (h&1){
            graph[i] = graph[c1] | graph[c2];
        }else{
            graph[i] = graph[c1] ^ graph[c2];
        }
    }
    // cout << "here" << endl;
    for (int i=0;i<m;i++){
        int j, b;
        cin >> j >> b;
        graph[j] = b;
        int par = j;
        int lend = 0;
        int h = 0;
        while (1){
            int c1, c2;
            int last = lend;
            lend += (1ll << (n-h));
            // cout << lend << endl;
            if (par&1){
                c1 = par;
                c2 = par+1;
            }else{
                c1 = par - 1;
                c2 = par;
            }
            par = lend + (c2 - last)/2;
            // cout << par << " " << c1 << " " << c2 << endl;
            h += 1;
            if (h&1){
                graph[par] = graph[c1] | graph[c2];
            }else{
                graph[par] = graph[c1] ^ graph[c2];
            }
            if (par == graph.size()-1){
                break;
            }
        }
        cout << graph[graph.size()-1] << endl;
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