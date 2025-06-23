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

    vector<int> s(m);
    rep(i, m) cin >> s[i];
    sort(all(s));

    int curr = m-1;
    vector<int> voil(n+1, m-1);
    vector<int> out(n+1, -1);
    out[1] = s[m-1];
    for (int i=2;i<=n;i++){
        if (m-1 == 0){
            cout << -1 << endl;return;
        }
        out[i] = s[voil[i]-1];
        
        for (int j=2*i;j<=n;j+=i){
            voil[j] = voil[i]-1;
            if (voil[i]-1 <= 0){
                cout << -1 << endl;return;
            }
        }
    }
    for (int i=1;i<=n;i++){
        cout << out[i] << " ";
    }cout << endl;

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