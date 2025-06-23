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

bool check(int mid, vi & a){
    int n = a.size();
    if (2*mid + 1 > a.size()){
        return 0;
    }
    vi b;
    int i = n-1;
    int j = mid-1;
    bool small = 0;
    for (int k=0;k<(2*mid + 1);k++){
        if (small){
            b.push_back(a[j]);
            j -= 1;
            small = 1 - small;
        }else{
            b.push_back(a[i]);
            small = 1 - small;
            i -= 1;
        }
    }
    while (i >= mid){
        b.push_back(a[i]);
        i--;
    }
    int ans = 0;
    for (i=1;i<(b.size()-1);i++){
        if (b[i] < b[i-1] && b[i] < b[i+1]){
            ans += 1;
        }
    }
    return ans >= mid;
}

void solve(){
    
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    int l = 0;
    int h = n/2;
    while (h - l > 1){
        int mid = (h + l)/2;
        if (check(mid, a)){
            l = mid;
        }else{
            h = mid - 1;
        }
    }
    vi b;
    int i = n-1;
    bool small = 0;
    if (check(h, a)){
        cout << h << endl;
        int j = h-1;
        for (int k=0;k<(2*h + 1);k++){
            if (small){
                b.push_back(a[j]);
                j -= 1;
                small = 1 - small;
            }else{
                b.push_back(a[i]);
                small = 1 - small;
                i -= 1;
            }
        }
        while (i >= h){
            b.push_back(a[i]);
            i--;
        }
        for (auto & ele: b){
            cout << ele << " ";
        }
    
    }else{
        cout << l << endl;
        int j = l-1;
        for (int k=0;k<(2*l + 1);k++){
            if (small){
                b.push_back(a[j]);
                j -= 1;
                small = 1 - small;
            }else{
                b.push_back(a[i]);
                small = 1 - small;
                i -= 1;
            }
        }
        while (i >= l){
            b.push_back(a[i]);
            i--;
        }
        for (auto & ele: b){
            cout << ele << " ";
        }
    }

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