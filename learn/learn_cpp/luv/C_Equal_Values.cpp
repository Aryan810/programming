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

    vi a(n);
    rep(i, n) cin >> a[i];

    vi maxcons(n+1, 0);
    vi cons(n+1, 0);
    vector<vector<int> > ind(n+1);

    for (int i=0;i<n;i++){
        int x = a[i];
        if (ind[x].size() == 0){
            // cout << "here" << endl;
            ind[x].push_back(i);
            cons[x] = 1;
        }else{
            if (i == ind[x].back() + 1){
                // cout << "here" << endl;
                ind[x].push_back(i);
                cons[x] += 1;
            }else{
                maxcons[x] = max(cons[x],  maxcons[x]);
                cons[x] = 1;
                ind[x].push_back(i);
            }
        }
    }
    for (int i=1;i<=n;i++){
        maxcons[i] = max(cons[i], maxcons[i]);
    }
    // for (auto ele: ind){
        
    //       if (ele.size() > 0){
    //           for (auto e: ele){
    //             cout << e << " ";
    //         }cout << endl;
    //       }
    // }
    // for (auto ele: cons){
    //     cout << ele << " ";
    // }cout << endl;
    int ans = 1e18;    
    for (int i=1;i<=n;i++){
        if (maxcons[i] != 0){
            int temp = (n - maxcons[i])*(i);
            ans = min(temp, ans);
        }
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