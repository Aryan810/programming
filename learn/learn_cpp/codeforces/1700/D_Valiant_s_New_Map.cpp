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
vector<multiset<int> > subg;
bool check(int mid, vvi & grid, int & n, int & m){
    vector<vector<int> > pref(n+1, vector<int>(m+1, 0));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int curr = 0;
            if (grid[i-1][j-1] >= mid){
                curr = 1;
            }
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + curr;
        }
    }

    

    for (int j=0;j<=(m-mid);j++){
        for (int i=0;i<=(n-mid);i++){
            int sm = pref[i+mid][j+mid] - pref[i][j+mid] - pref[i+mid][j] + pref[i][j];
            if (sm >= mid*mid){
                return 1;
            }
        }
    }
    return 0;
}       

void solve(){
    
    int n, m;
    cin >> n >> m;

    vector<vector<int> > grid(n, vector<int>(m));
    rep(i, n){
        rep(j, m){
            cin >> grid[i][j];
        }
    }

    int l = 1;
    int h = min(n, m);

    while (h - l > 1){
        int mid = (h + l)/2;
        if (check(mid, grid, n, m)){
            l = mid;
        }else{
            h = mid - 1;
        }
    }

    if (check(h, grid, n, m)){
        cout << h << endl;
    }else{
        cout << l << endl;
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