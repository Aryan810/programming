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
    
    int n, a, b;
    cin >> n >> a >> b;

    vi c(n);
    vi cum(n+1);
    cum[0] = 0;
    int sm = 0;
    rep(i, n){
        int x;
        cin >> x;
        sm += x;
        cum[i+1] = sm;
        c[i] = x;
    }
    multiset<int> ms; 
    int ans = -1e18;  
    for (int i=(n-a+1);i>0;i--){
        // cout << ms.size() << endl;
        if (ms.size() < (b-a+1)){
            ms.insert(cum[i+a-1]);
        }else{
            ms.insert(cum[i+a-1]);
            ms.erase(ms.find(cum[i+b]));
        }
        int mx = *(--ms.end());
        ans = max(ans, mx-cum[i-1]);
    }

    cout << ans << endl;


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test = 1;

    while(test--){
        solve();
    }

    return 0;
}