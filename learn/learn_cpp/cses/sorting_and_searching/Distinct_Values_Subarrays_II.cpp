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
    
    int n, k;
    cin >> n >> k;

    vi a(n);
    rep(i, n) cin >> a[i];

    int right = 0;
    int left = 0;
    int dist = 1;
    int ans = 0;
    map<int, int> cnt;
    cnt[a[right]] += 1;
    while (right < n){
        if (dist <= k){
            ans += right - left + 1;
            // cout << dist << endl;
            //             cout << left << " " << right << " " << ans << endl;

        }else{
            while (dist > k){
                cnt[a[left]] -= 1;
                if (cnt[a[left]] == 0){
                    dist -= 1;
                }
                left += 1;
            }
            ans += right - left + 1;    
            // cout << dist << endl;

                        // cout << left << " " << right << " " << ans << endl;
  
        }
        right += 1;
        if (right < n){
            cnt[a[right]] += 1;
            if (cnt[a[right]] == 1){
                dist += 1;
            }
        }
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