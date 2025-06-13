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

int findfreq(int up, int down, int k){
    if (up < down){
        if (down >= k){
            return min(up, k);
        }else{
            return min(up + down - k, k);
        }
    }else{
        if (up >= k){
            return min(down, k);
        }else{
            return min(up + down - k, k);
        }
    }
}

void solve(){
    
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    vi a(w);
    rep(i, w) cin >> a[i];

    sort(rall(a));
    multiset<int> freq;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int up = i+1;
            int down = n - i;
            int right = m - j;
            int left = j + 1;
            freq.insert(findfreq(up, down, k) * findfreq(left, right, k));
        }
    }

    auto it = --freq.end();
    int ans = 0;
    for (int i=0;i<w;i++){
        ans += a[i] * (*it);
        it--;
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