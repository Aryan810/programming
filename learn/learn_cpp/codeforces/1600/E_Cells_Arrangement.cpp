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
    if (n == 2){
        cout << "1 1" << endl << "2 2" << endl;cout << endl;
        return;
    }else if (n == 3){ 
        cout << "1 1\n3 3\n2 3" << endl;cout << endl;
        return;
    }
    if (n&1){
        int left = n-2;
        cout << "1 1\n" << n << " " << n << endl;
        int dist = 2;
        while (left > 0){
            if (dist == 2){
                cout << dist << " " << 1 << endl;
                dist += 1;
            }else{
                cout << 1 << " " << dist << endl;
                dist += 1;
            }
            left -= 1;
        }
    }else{
        int left = n-2;
        cout << "1 1\n" << n << " " << n << endl;
        int dist = 2;
        while (left > 0){
            if (dist&1){
                cout << dist << " " << 1 << endl;
                dist += 1;
            }else{
                cout << n-dist+1 << " " << n << endl;
                dist += 1;
            }
            left -= 1;
        }
    }
    cout << endl;


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