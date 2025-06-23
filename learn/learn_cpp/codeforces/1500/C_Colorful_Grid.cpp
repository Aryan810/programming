// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>
const int M = 1e9 + 7;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){
    
    int n, m;
    cin >> n >> m;
    int k;cin >> k;
    k -= n + m - 2;
    if (k < 0 || k & 1){
        cout << "NO" << endl;return;
    }
    cout << "YES" << endl;
    vector<vector<char> > grid1(n, vector<char>(m-1, -1));
    vector<vector<char> > grid2(n-1, vector<char>(m, -1));
    int par = 1;
    // for (int i=0;i<n;i++){
    for (int j=0;j<(m-1);j++){
        if (par){
            grid1[0][j] = 1;
            par = 1 - par;
        }else{
            grid1[0][j] = 0;
            par = 1 - par;
        }
    }
    for (int j=0;j<(n-1);j++){
            if (par){
                grid2[j][m-1] = 1;
                par = 1 - par;
            }else{
                grid2[j][m-1] = 0;
                par = 1 - par;
            } 
    }
    
    if (k%4 == 0){
        grid2[n-2][m-2] = grid2[n-2][m-1];
        grid1[n-1][m-2] = 1 - grid2[n-2][m-2];
        grid1[n-2][m-2] = grid1[n-1][m-2];
    }else{
        grid2[n-2][m-1] = grid2[n-3][m-1];
        grid2[n-2][m-2] = grid2[n-2][m-1];
        grid1[n-1][m-2] = 1 - grid2[n-2][m-1];
        grid1[n-2][m-2] = grid1[n-1][m-2];
    }

    for (auto & ele: grid1){
        for (auto & e: ele){
            if (e == -1){
                cout << "R ";
            }else{
                cout << (e?"R ":"B ");
            }
        }cout << endl;
    }
    for (auto & ele: grid2){
        for (auto & e: ele){
            if (e == -1){
                cout << "R ";
            }else{
                cout << (e?"R ":"B ");
            }
        }cout << endl;
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}