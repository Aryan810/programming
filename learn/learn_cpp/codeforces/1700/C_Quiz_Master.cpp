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
vector<int> fac[100001];
void solve(){
    
    int n, m;
    cin >> n >> m;
   
    vi a(n);
    rep(i, n) cin >> a[i];
    if (m == 1){
        cout << 0 << endl;return;
    }
    sort(all(a));
    vector<int> req(m+1, 0);
    for (int i=1;i<=m;i++){
        if (m-i < i){
            req[i] = 1;
        }
    }
    vector<int> cnt(m+1, 0);
    // for (int i=0;i<n;i++){
    //     for (auto & f: fac[a[i]]){
    //         if (f <= m && req[f]){
    //             cnt[f] += 1;
    //         }
    //     }
    // }
    // for (int i=1;i<=m;i++){
    //     if (req[i] && cnt[i] <= 0){
    //         cout << -1 << endl;return;
    //     }
    // }
    int i = 0;  
    int j = n-1;
    int u = 0;
    int ans = 1e18;
    bool found = 0;
    for (int i=0, j=0;i<n;i++){
        while (j < n && u < m){
            for (auto & it: fac[a[j]]){
                // cout << it << endl;
                if (it <= m){
                    cnt[it]++;
                    if (cnt[it] == 1){
                        u += 1;
                    }
                }
            }
            j++;
        }
        // cout << u << endl;
        if (u >= m){
            found = 1;
            ans = min(ans, abs(a[i]-a[j-1]));
        }
        for (auto & it: fac[a[i]]){
            if (it <= m){
                cnt[it]--;
                if (cnt[it] == 0){
                    u -= 1;
                }
            }
        }
    }
    if (found){cout << ans << endl;}else{
        cout << -1 << endl;return;
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test;
    cin >> test;
    int n = 1e5;
    for (int i=1;i<=1e5;i++){
        for (int j=i;j<=n;j+=i){
            fac[j].push_back(i);
        }
    }
    while(test--){
        solve();
    }

    return 0;
}