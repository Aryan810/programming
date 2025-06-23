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

    if ((n*(n+1))/2 < m || m < n){
        cout << -1 << endl;return;
    }
    if (m == (n*(n+1))/2){
        cout << n << endl;
        for (int i=1;i<n;i++){
            cout << i << " " << n << endl;
        }
        return;
    }else if (m == n){
        cout << 1 << endl;
        for (int i=2;i<=n;i++){
            cout << 1 << " " << i << endl;
        }
        return;
    }
    int sm = 0;
    int ex = 0;
    int last = 0;
    for (int i=1;i<=n;i++){
        sm += i;
        if (sm+(n-i) > m){
            sm -= i;
            last = i-1;
            ex = m - sm;
            break;
        }
    }
    int lft = n - last;
    if (ex < lft){
        cout << -1 << endl;return;
    }
    // if (last+1 == ex){
        int exx = ex - lft + 1;
        int one = lft - 1;
        int rt = last;
        cout << rt << endl;
        for (int i=last+1;i<n;i++){
            cout << "1 " << i << endl;
        }
        cout << exx << " " << n << endl;
        for (int i=1;i<last;i++){
            cout << i << " " << rt << endl;
        }
    //     return;
    // }

    // int exx = ex - lft + 1;
    // int one = lft - 1;
    // int rt = last;
    // for (int i=last+1;i<n;i++){
    //     cout << "1 " << i << endl;
    // }
    // cout << exx << " " << n << endl;
    // for (int i=1;i<last;i++){
    //     cout << i << " " << rt << endl;
    // }



    
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