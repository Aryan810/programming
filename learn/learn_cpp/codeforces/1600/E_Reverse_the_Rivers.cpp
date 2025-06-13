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

    int n, k, q;
    cin >> n >> k >> q;

    vector<vector<int> > a(k, vector<int>(n, 0));
    vector<vector<int> > water(k, vector<int>(n, 0));
    for (int i=0;i<n;i++){
        for (int j=0;j<k;j++){
            cin >> a[j][i];
        }
    }
    for (int i=0;i<k;i++){
        int temp = 0;
        for (int j=0;j<n;j++){
            temp = temp | a[i][j];
            water[i][j] = temp;
        }
    }
    // for (int i=0;i<n;i++){
    //     for (int j=0;j<k;j++){
    //         cout << a[j][i] << " ";
    //     }cout << endl;
    // }
    // for (int i=0;i<n;i++){
    //     for (int j=0;j<k;j++){
    //         cout << water[j][i] << " ";
    //     }cout << endl;
    // }

    for (int i=0;i<q;i++){
        int m;
        cin >> m;
        int l = 0;
        int h = n-1;
        for (int j=0;j<m;j++){
            // cout << i << " " << j << endl;
            int r;
            char x;
            int w;
            cin >> r >> x >> w;
            r -= 1;
            int p, q;
            if (x == '>'){
                auto it = upper_bound(all(water[r]), w);
                p = it - water[r].begin();
                q = n-1;
            }else{
                // cout << "HERE" << endl;
                auto it = lower_bound(all(water[r]), w);
                p = 0;
                q = it - water[r].begin() - 1;
            }
            l = max(l, p);
            h = min(h, q);
            // cout << p << " <--> " << q << endl;
            // cout << l << " <-> " << h << endl << endl;

        }
         if (l > h){
        cout << -1 << endl;
        }else {
            cout << l+1 << endl;
        }
    }
   

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    
    return 0;
}