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
int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = (ans * a)%M;
        }
        a = (a * a)%M;
        b >>= 1;
    }
    return ans;
}
void solve(){
    
    int n;
    cin >> n;
    set<int> s;
    // multiset<int> ms;
    map<int, int> cnt;
    int v = 1;
    vi a(n);
    rep(i, n){
        int x;
        cin >> x;
        a[i] = x;
        cnt[x] += 1;
        s.insert(x);
        // ms.insert(x);
    }
    for (auto ele: s){
        v *= (cnt[ele] + 1);
        v %= M;
    }
    // cout << v.val() << endl;
    int ans = 0;
    for (int i=0;i<n;i++){
        ans += (v * binexpiter(cnt[a[i]]+1, M-2))%M;
      
        ans %= M;
        v *= (cnt[a[i]]);
        v %= M;
        v = (v * binexpiter(cnt[a[i]] + 1, M-2))%M;
        cnt[a[i]] -= 1;
    }
    cout << ans << endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    // int test;
    // cin >> test;

    // while(test--){
        solve();
    // }

    return 0;
}