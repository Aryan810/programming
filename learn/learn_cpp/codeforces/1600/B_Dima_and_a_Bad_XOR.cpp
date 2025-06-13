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

    int n, m;
    cin >> n >> m;
    vector<vector<int> > grid(n, vector<int>(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }

    // int ans = helper(0, 0, n, grid);
    // cout << ((ans)?"TAK":"NIE") << endl;

    for (int i=0;i<=10;i++){
        array<int, 3> x = {0, 0, 0};
        vector<int> cnt(n);
        for (int j=0;j<n;j++){
            int one = 0;
            for (int k=0;k<m;k++){
                if (grid[j][k]&(1<<i)){
                    one += 1;
                }
            }
            if (one == m){
                x[1] += 1;
            }else if (one == 0){
                x[2] += 1;
            }else{
                x[0] += 1;
            }
            cnt[j] = one;
        }
        if (x[0] > 0){
            cout << "TAK" << endl;
            if (x[1]&1){
                for (int l=0;l<n;l++){
                    if (cnt[l] == m){
                        cout << 1 << " ";
                    }else if (cnt[l] == 0){
                        cout << 1 << " ";
                    }else{
                        for (int j=0;j<m;j++){
                            if (grid[l][j]&(1<<i)){}else{
                                cout << j+1 << " ";
                                break;
                            }
                        }
                    }
                }
            }else{
                bool done = 0;
                for (int l=0;l<n;l++){
                    if (cnt[l] == m){
                        cout << 1 << " ";
                    }else if (cnt[l] == 0){
                        cout << 1 << " ";
                    }else{
                        for (int j=0;j<m;j++){
                            if (!done){
                                if (grid[l][j]&(1<<i)){
                                    cout << j+1 << " ";
                                    done = 1;
                                    break;
                                }
                            }else{
                                if (grid[l][j]&(1<<i)){}else{
                                    cout << j+1 << " ";
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            return;
        }else if (x[1]&1){
            cout << "TAK" << endl;
            for (int l=0;l<n;l++){
                    if (cnt[l] == m){
                        cout << 1 << " ";
                    }else if (cnt[l] == 0){
                        cout << 1 << " ";
                    }else{
                        for (int j=0;j<m;j++){
                            if (grid[l][j]&(1<<i)){}else{
                                cout << j+1 << " ";
                                break;
                            }
                        }
                    }
                }
            return;
        }
    }
    cout << "NIE" << endl;

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