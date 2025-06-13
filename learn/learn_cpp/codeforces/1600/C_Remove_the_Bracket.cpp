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

    int n, s;
    cin >> n >> s;

    vi a(n);
    rep(i, n) cin >> a[i];

    vector<pair<int, int> > v(n);
    for (int i=1;i<n-1;i++){
        if (a[i] < s){
            v[i] = {0, a[i]};
        }else{
            v[i] = {min(s, a[i]-s), max(s, a[i]-s)};
        }
    }
    // for (auto ele: v){
    //     cout << ele.first << " " << ele.second << endl;
    // }
    vector<pair<int, int> > dp(n+1);
    dp[0] = {a[0]*v[1].first, a[0]*v[1].second};
    for (int i=1;i<n-2;i++){
        int x = dp[i-1].first+(v[i].second)*v[i+1].first;
        int y = dp[i-1].second+(v[i].first)*v[i+1].first;
        int x1 = dp[i-1].first+(v[i].second)*v[i+1].second;
        int y1 = dp[i-1].second+(v[i].first)*v[i+1].second;
        dp[i] = {min(x, y), min(x1, y1)};
    }
    dp[n-2] = {dp[n-3].first + v[n-2].second*a[n-1], dp[n-3].second + v[n-2].first*a[n-1]};
    // for (auto ele: dp){
    //     cout << ele.first << " ";
    // }cout << endl;
    // for (auto ele: dp){
    //     cout << ele.second << " ";
    // }cout << endl;
    cout << min(dp[n-2].first, dp[n-2].second) << endl;



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