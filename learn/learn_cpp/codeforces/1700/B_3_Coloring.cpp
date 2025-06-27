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

    vector<pair<int, int> > evenpos;
    vector<pair<int, int> > oddpos;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if ((i+j)&1){
                oddpos.push_back({i, j});
            }else{
                evenpos.push_back({i, j});
            }
        }
    }
    int odddone = 0;
    int evendone = 0;
    for (int i=0;i<n*n;i++){
        int a;
        cin >> a;
        if (a == 1){
            if (oddpos.size() == 0){
                cout << 3 << " " << evenpos.back().first << " " << evenpos.back().second << endl;cout.flush();
                evenpos.pop_back();
            }else{
                cout << 2 << " " << oddpos.back().first << " " << oddpos.back().second << endl;cout.flush();
                oddpos.pop_back();
            }
        }else if (a == 2){
            if (evenpos.size() == 0){
                cout << 3 << " " << oddpos.back().first << " " << oddpos.back().second << endl;cout.flush();
                oddpos.pop_back();
            }else{
                cout << 1 << " " << evenpos.back().first << " " << evenpos.back().second << endl;cout.flush();
                evenpos.pop_back();
            }
        }else{
            if (evenpos.size() == 0){
                cout << 2 << " " << oddpos.back().first << " " << oddpos.back().second << endl;cout.flush();
                oddpos.pop_back();
            }else{
                cout << 1 << " " << evenpos.back().first << " " << evenpos.back().second << endl;cout.flush();
                evenpos.pop_back();
            }
        }
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