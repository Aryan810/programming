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
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int> > grid(n, vector<int>(m));
    vector<vector<int> > cum(n+1, vector<int>(m+1, 0));
    int gold = 0;
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        for (int j=0;j<m;j++){
            if (s[j] == '.'){
                grid[i][j] = 0;
            }else if (s[j] == 'g'){
                grid[i][j] = 1;
                gold += 1;
            }else{
                grid[i][j] = -1;
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cum[i][j] = cum[i-1][j] + cum[i][j-1] - cum[i-1][j-1] + ((grid[i-1][j-1]==1)?1:0);
            // cout << i << " " << j << " " 
            // << cum[i][j] << " " << cum[i-1][j-1] << " " 
            // << cum[i][j-1] << " " << cum[i-1][j] << endl;
        }
    }
    
    //  for (auto ele: cum){
    //     for (auto e:ele){
    //         cout << e << " ";
    //     }cout << endl;
    // }
    int mn = 1e18;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (grid[i][j] == 0){
                int side = 2*k - 1;
                int mh = i+side/2+1;
                int mw = j+side/2+1;
                int mnh = i-side/2;
                int mnw = j-side/2;
                if (mh > n){
                    mh = n;
                }
                if (mw > m){
                    mw = m;
                }
                if (mnh < 0){
                    mnh = 0;
                }
                if (mnw < 0){
                    mnw = 0;
                }
                int temp = cum[mh][mw] + cum[mnh][mnw] - cum[mh][mnw] - cum[mnh][mw];

                mn = min(temp, mn);
            }
        }
    }
    cout << gold - mn << endl;

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