#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// DSU
const int N = 1e5+10;
int parent[N];
int sz[N];

void make(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find(int v){
    if (v == parent[v]){return v;}
    return parent[v] = find(parent[v]);
}

void Union(int i, int j){
    int p = find(i);
    int q = find(j);
    if (p != q){
        if (sz[p] > sz[q]){
            parent[q] = p;
            sz[p] += sz[q];
        }else{
            parent[p] = q;
            sz[q] += sz[p];
        }
    }
}

void solve(){

    int n, x;
    cin >> n >> x;

    vi a(n);
    rep(i, n) cin >> a[i];
    int def = 0;
    for (int i=0;i<(n-1);i++){
        def += abs(a[i]-a[i+1]);
    }
    // if (n == 1){
    //     if (a[0] >= x){cout << x-1+min(abs(a[0]-x), abs(1-a[0])) << endl;}else{
    //         cout << x-1 << endl;
    //     }
    //     return;
    // }
    int mn = *min_element(all(a));
    int mx = *max_element(all(a));

    int ans = 1e18;
    int f1 = max(0ll, mn-2);
    int f2 = max(0ll, x-mx-1);
    // cout << f1 << " " << f2 << " " << def << endl;
    // case 1 => mx == x
    if (mx >= x && mn == 1){
        ans = def;
    }else if (mx < x && mn == 1){
        int t = max(a[0], a[n-1]);
        ans = min(ans, def+f2+min(mx+1-t, mx+1+x-2*(mx)));
    }else if (mx >= x && mn != 1){
        int t = min(a[0], a[n-1]);
        ans = min(ans, def+f1+min(t-mn+1, mn));
    }else{
        int l = max(a[0], a[n-1]);
        int s = min(a[0], a[n-1]);
        ans = min(ans, def + f1 + f2 + min(s-mn+1, mn) + min(mx+1-l, mx+1+x-2*mx));
    }
    cout << ans << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}