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

    vector<vector<int> > a(n, vector<int>(m)), at(m, vector<int>(n)), b(n, vector<int>(m)), bt(m, vector<int>(n));


    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int x;
            cin >> x;
            a[i][j] = x;
            at[j][i] = x;
        }
        sort(all(a[i]));
    }
    for (int i=0;i<m;i++){
        sort(all(at[i]));
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int x;
            cin >> x;
            b[i][j] = x;
            bt[j][i] = x;
        }
        sort(all(b[i]));
    }
    for (int i=0;i<m;i++){
        sort(all(bt[i]));
    }   

    // cout << endl;
    // for (auto ele: a){
    //     for (auto e: ele){
    //         cout << e << " ";
    //     }cout << endl;
    // }
    // cout << endl;
    // for (auto ele: b){
    //     for (auto e: ele){
    //         cout << e << " ";
    //     }cout << endl;
    // }
    // cout << endl;

    // for (auto ele: at){
    //     for (auto e: ele){
    //         cout << e << " ";
    //     }cout << endl;
    // }
    // cout << endl;

    // for (auto ele: bt){
    //     for (auto e: ele){
    //         cout << e << " ";
    //     }cout << endl;
    // }
    // cout << endl;


    map<int, int> v1;
    for (int i=0;i<n;i++){
        v1[b[i][0]] = i+1;
    }
    for (int i=0;i<n;i++){
        
        if (v1[a[i][0]] == 0){
            cout << "NO" << endl;return;
        }
        for (int j=0;j<m;j++){
            if (a[i][j] != b[v1[a[i][0]]-1][j]){
                cout << "NO" << endl;return;
            }
        }
    }
    // cout << "here" << endl;
    map<int, int> v2;
    for (int i=0;i<m;i++){
        v2[bt[i][0]] = i+1;
    }
    for (int i=0;i<m;i++){
        // cout << at[i][i] << " " << v2[at[i][0]]
        if (v2[at[i][0]] == 0){
            cout << "NO" << endl;return;
        }
        for (int j=0;j<n;j++){
            if (at[i][j] != bt[v2[at[i][0]]-1][j]){
                cout << "NO" << endl;return;
            }
        }
    }

    cout << "YES" << endl;




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