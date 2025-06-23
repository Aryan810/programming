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
    
    int n, m;
    cin >> n >> m;

    vi a;
    map<int, int> cnt;
    rep(i, n){
        int x;
        cin >> x;
        cnt[x] += 1;
        if (cnt[x] == 1){
            a.push_back(x);
        }
    }
    
    sort(all(a));

    int temp = 1;
    int ans = 0;
    int i = 0;
    int j = 0;
    set<int> dist;
    while (i < a.size() && j < a.size()){
        while (j < a.size() && a[j] <= a[i]+m-1){
            temp *= cnt[a[j]];
            temp %= M;
            dist.insert(a[j]);
            j += 1;
        }
        // cout << i << " " << j << endl;
        if (dist.size() < m || a[j-1] != a[i]+m-1){
            temp *= binexpiter(cnt[a[i]], M-2);
            temp %= M;
            dist.erase(a[i]);
            i += 1;
            continue;
        }
        ans += temp;
        ans %= M;
        temp *= binexpiter(cnt[a[i]], M-2);
        temp %= M;
        dist.erase(a[i]);
        i += 1;
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