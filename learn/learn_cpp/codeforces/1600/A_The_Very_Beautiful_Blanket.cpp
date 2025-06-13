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

void solve(){

    int n, m;
    cin >> n >> m;

    int h = 512;
    int w = 512;
    // cout << h << " " << w << endl;

    vector<vector<int> > grid1(h, vector<int>(w));
    int curr = 0;
    for (int i=0;i<h;i+=2){
        for (int j=0;j<w;j+=2){
            grid1[i][j] = 4*curr;
            grid1[i][j+1] = 4*curr + 1;
            grid1[i+1][j] = 4*curr + 2;
            grid1[i+1][j+1] = 4*curr + 3;
            curr += 1;
        }
    }

    cout << n*m << endl;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout << grid1[i][j] << " ";
        }cout << endl;
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