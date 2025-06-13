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

    int n;
    cin >> n;
    vector<vector<int> > grid(2*n, vector<int>(2*n, 0));
    int total = 0;

    for (int i=0;i<n;i++){
        string s;cin >> s;
        for (int j=0;j<n;j++){
            grid[i][j] = s[j]-'0';
            total += grid[i][j];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            grid[i+n][j] = grid[i][j];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            grid[i][j+n] = grid[i][j];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            grid[i+n][j+n] = grid[i][j];
        }
    }

    vector<vector<int> > cum(4*n - 1);
    int offset = 2*n - 1;
    for (int i=(2*n-1);i>=(1-2*n);i--){
        vector<int> temp;
        temp.push_back(0);
        int sm = 0;
        if (i >= 0){
            int f = i;
            int l = 2*n-1;
            for (int x=f;x<=l;x++){
                int y = x - i;
                sm += grid[x][y];
                temp.push_back(sm);
            }
            cum[i+offset] = temp;
        }else{
            int f = -1*i;
            int l = 2*n-1;
            for (int y=f;y<=l;y++){
                int x = y + i;
                sm += grid[x][y];
                temp.push_back(sm);
            }
            cum[i+offset] = temp;
        }
    }

    // for (auto ele: cum){
    //     for (auto e: ele){
    //         cout << e << " ";
    //     }cout << endl;
    // }




    int mx = 0;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){ 
            int ind = i-j+offset;
            int pos;
            if (i-j >= 0){
                pos = j;
            }else{
                pos = i;
            }
            mx = max(mx, cum[ind][pos+n]-cum[ind][pos]);
        }
    }
    cout << (n-mx) + (total-mx) << endl;
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