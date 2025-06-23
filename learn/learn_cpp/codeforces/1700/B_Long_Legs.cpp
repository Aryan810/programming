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
    
    int a, b;
    cin >> a >> b;
    int ans = 1e18;
    for (int k=1;k <= 1e5;k++){
        ans = min(ans, (a+k-1)/k + (b+k-1)/k + k-1);
    }
    // cout << f << " " << s << " " << req << " " << req1 << endl;
    cout << (ans) << endl;
    // int f = 1e18;
    // int sm = 0;
    // for (int i=1;(i*(i+1))/2 <= a;i++){
    //     if (i == 1){
    //         f = min(f, a);
    //     }else if ((a - sm)%i == 0){
    //         f = min(f, 2*i - 3 + (a-sm)/i);
    //     }
    //     sm += i;
    // }
    // int ans = f;
    // f = 1e18;
    // sm = 0;
    // for (int i=1;(i*(i+1))/2 <= b;i++){
    //     if (i == 1){
    //         f = min(f, b);
    //     }else if ((b - sm)%i == 0){
    //         f = min(f, 2*i - 3 + (b-sm)/i);
    //     }
    //     sm += i;
    // }
    // ans += f;
    // cout << ans << endl;
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