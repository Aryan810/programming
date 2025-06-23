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

    vector<int> cnt(n+m+1, 0);
    vi a(n);
    rep(i, n){
        int x;
        cin >> x;
        cnt[x] = m+1;
        a[i] = x;
    }

    for(int i=0;i<m;i++){
        int p, v;
        cin >> p >> v;
        if (a[p-1] != v){
            cnt[v] += m-i;
            cnt[a[p-1]] -= m-i;
            a[p-1] = v;
        }

    }


    int ans = 0;
    int diff = 0;
    for (int i=1;i<=(n+m);i++){
        ans += (cnt[i]*(m+1-cnt[i]) + (cnt[i]*(cnt[i]-1))/2);
     
    }
    // cout << diff << endl;
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