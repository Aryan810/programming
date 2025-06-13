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

int helper(int i, int done, vi & c, vi & d, int k, vector<vector<int> > & dp){
    if (i >= c.size() || done > k){
        return 0;
    }
    if (dp[i][done] != -1){
        return dp[i][done];
    }
    int ret = helper(i+1, done, c, d, k, dp);
    if (done+d[i] <= k){
        ret = max(ret, helper(i+1, done+d[i], c, d, k, dp) + c[i]);
    }
    return dp[i][done] = ret;
}

vector<int> oper(1002, INT_MAX);

void solve(){
    int n, k;
    cin >> n >> k;
    vi b(n);
    rep(i, n) cin >> b[i];
    vi c(n);
    rep(i, n) cin >> c[i];
    int sm = 0; 
    for (int i=0;i<n;i++){
        sm += oper[b[i]];
        b[i] = oper[b[i]];
    }
    if (k >= sm){
        cout << accumulate(all(c), 0ll) << endl;return;
    }
    vector<vector<int> > dp(n+1, vector<int>(k+1, -1));
    // vector<vector<int> > dp(n+1, vector<int>(k+1, 0));
    // for (int i=1;i<=n;i++){
    //     for (int j=0;j<=k;j++){
    //         if (j >= b[i-1]){
    //             dp[i][j] = dp[i-1][j-b[i-1]] + c[i-1];
    //         }
    //         dp[i][j] = max(dp[i][j], dp[i-1][j]);
    //     }
    // }
    cout << helper(0, 0, c, b, k, dp) << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    oper[1] = 0;
    for (int i=1;i<=1000;i++){
        for (int j=i;j>=1;j--){
            int to = i+i/j;
            if (to > 1000){
                break;
            }
            oper[to] = min(oper[to], oper[i]+1);
        }
    }

    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}