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

    int n;
    cin >> n;

    vector<vector<int> > grid(n, vector<int>(n, 0));

    int i = (n-1)/2;
    int j = (n-1)/2;
    int curr = 1;
    grid[i][j] = 0;
    int d = 1;
    int h = 1;
    int f = 1;
    while ((i >= 0 && i < n) && (j < n && j >= 0)){
        // cout << i << " " << j << endl;
        if (h){
            for (int k=0;k<d;k++){
                j += f;
                if (curr < n*n){
                    grid[i][j] = curr++;
                }
            }
            h = 0;
        }else{
            for (int k=0;k<d;k++){
                i += f;
                if (curr < n*n){
                    grid[i][j] = curr++;
                }
            }
            d += 1;
            f = -1 * f;
            h = 1;
        }
        if (n&1){
            if (i == 0 && j == n-1){
                break;
            }
        }else{
            if (i == n-1 && j == 0){
                break;
            }
        }
    }
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            cout << grid[i][j] << " ";
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