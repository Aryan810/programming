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
    
    int n, q;
    cin >> n >> q;

    vector<vector<int> > grid(2, vector<int>(n));
    int one = 0;
    for (int i=0;i<2;i++){
        string s;
        cin >> s;
        for (int j=0;j<n;j++){
            grid[i][j] = s[j] - '0';
            one += grid[i][j];
        }
    }

    if (one < n+1){
        cout << -1 << endl;return;
    }

    vector<int> pref;
    int zero = 0;
    int r1 = 0;
    int tot = 0;
    for (int i=0;i<n;i++){
        if (grid[0][i] == 0){
            zero += 1;
        }else{
            tot += zero;
            pref.push_back(tot);
            r1 += 1;
        }
    }

    vector<int> suf;
    zero = 0;
    int r2 = 0;
    tot = 0;
    for (int i=n-1;i>=0;i--){
        if (grid[1][i] == 0){
            zero += 1;
        }else{
            tot += zero;
            suf.push_back(tot);
            r2 += 1;
        }
    }
    // for (auto ele: suf){
    //     cout << ele << " ";
    // }cout << endl;
    int ans = 1e18;

    if (r1 < r2){
        for (int i=0;i<r1;i++){
            if (n-i-1 < suf.size() && i < pref.size()){
                int op = pref[i] + suf[n-i-1];
                // cout << i << " " << op << endl;
                ans = min(ans, op);
            }
        }
    }else{
        for (int i=0;i<r2;i++){
            if (n-i-1 < pref.size() && i < suf.size()){
                int op = suf[i] + pref[n-i-1];
                ans = min(ans, op);
            }

        }
    }
    cout << ans << endl;


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