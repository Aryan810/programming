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

    int n, q;
    cin >> n >> q;
    int MH = 1001;
    int MW = 1001;
    vector<vector<int> > grid(1002, vector<int>(1002, 0));
    for (int i=0;i<n;i++){
        int h, w;
        cin >> h >> w;
        grid[h][w] += h*w;
    }
    vector<vector<int> > cum(1002, vector<int>(1002, 0));
    int sm = 0;
    for (int i=1;i<=MH;i++){
        sm += grid[i][1];
        cum[i][1] = sm;
    }
    sm = 0;
    for (int i=1;i<=MW;i++){
        sm += grid[1][i];
        cum[1][i] = sm;
    }

    for (int i=2;i<=MH;i++){
        for (int j=2;j<=MW;j++){
            cum[i][j] = cum[i-1][j] + cum[i][j-1] - cum[i-1][j-1] + grid[i][j];
        }
    }

    for (int i=0;i<q;i++){
        int h1, w1, h2, w2; cin >> h1 >> w1 >> h2 >> w2;
        h1 += 1;
        w1 += 1;
        h2 -= 1;
        w2 -= 1;
        int ans = cum[h2][w2] - cum[h1-1][w2] - cum[h2][w1-1] + cum[h1-1][w1-1];
        cout << ans << endl;
    }


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