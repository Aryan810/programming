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
const int N = 1e6 + 1;
int cnt[N];



void solve(){
    
    int n;
    cin >> n;

    vi a;
    int ans = 0;
    int mx = 0;
    rep(i, n){
        int x;
        cin >> x;
        cnt[x] += 1;
        mx = max(mx, x);
        if (cnt[x] == 1){
            a.push_back(x);
        }
    }
    sort(all(a));
    for (int i=0;i<a.size();i++){
        ans += cnt[a[i]]*(cnt[a[i]]-1)*(cnt[a[i]]-2);
    }
    for (int j=a.size()-1;j>=0;j--){
        for (int i=2;a[j]*i*i<=mx;i++){
            if (cnt[a[j]*i] > 0 && cnt[a[j]*i*i] > 0){
                ans += (cnt[a[j]])*(cnt[a[j]*i])*(cnt[a[j]*i*i]);
            }
        }
    }
    cout << ans << endl;
    for (int i=0;i<a.size();i++){
        cnt[a[i]] = 0;
    }
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