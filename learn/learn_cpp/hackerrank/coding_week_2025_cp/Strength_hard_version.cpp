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

    int h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    vector<vector<int> > cumGrid(h, vector<int>(w, 0));
    
    for (int i=0;i<n;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        vector<array<int, 3> > updates = {
            {a, b, 1}, {c+1, d+1, 1}, {c+1, b, -1}, {a, d+1, -1}
        };
        for (auto ele: updates){
            if ((ele[0] >= 1 && ele[0] <= h) && (ele[1] >= 1 && ele[1] <= w)){
                cumGrid[ele[0]-1][ele[1]-1] += ele[2];
            }
        }
    }
    // for (auto ele: cumGrid){
    //     for (auto e: ele){
    //         cout << e << " ";
    //     }cout << endl;
    // }cout << endl;
    int sm = 0;
    vector<vector<int> > grid(h, vector<int>(w, 0));
    int mx = 0;

    for (int i=0;i<h;i++){
        sm += cumGrid[i][0];
        grid[i][0] = sm;
        mx = max(mx, grid[i][0]);
    }
    sm = 0;
    for (int i=0;i<w;i++){
        sm += cumGrid[0][i];
        grid[0][i] = sm;
        mx = max(mx, grid[0][i]);
    }
    for (int i=1;i<h;i++){
        for (int j=1;j<w;j++){
            grid[i][j] = grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1] + cumGrid[i][j];
            mx = max(mx, grid[i][j]);
        }
    }
    //  for (auto ele: grid){
    //     for (auto e: ele){
    //         cout << e << " ";
    //     }cout << endl;
    // }cout << endl;
    // cout << mx << endl;
    int num = 0;
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            if (grid[i][j] == mx){
                // cout << i+1 << " " << j+1 << endl;
                num += 1;
            }
        }
    }
    cout << num << endl;
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            if (grid[i][j] == mx){
                cout << i+1 << " " << j+1 << endl;
            }
        }
    }


}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int test;
    // cin >> test;

    // while(test--){
        solve();
    // }

    return 0;
}