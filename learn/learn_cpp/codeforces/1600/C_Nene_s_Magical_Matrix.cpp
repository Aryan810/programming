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

    // finding sm
    int s = 0;
    for (int i = 1;i<=n;i++){
        s += i * (2*i - 1);
    }
    int k = 2*n - 1;

    cout << s << " " << k << endl;
    int h = 1, v = 1;
    bool hor = 1;
    int row = 1;
    int col = 2;
    for (int i=0;i<k;i++){
        if (hor){
            cout << "1 ";
            cout << row << " ";
            int j = 0;
            int m = n;
            while (j < n){
                if (j == h){
                    cout << "1 ";
                }else{
                    cout << m << " ";m--;
                }
                j += 1;
            }
            h += 1;
            hor = 0;
            row += 1;
        }else{
            cout << "2 ";
            cout << col << " ";
            int j = 0;
            int m = n;
            while (j < n){
                if (j == v){
                    cout << "1 ";
                }else{
                    cout << m << " ";m--;
                }
                j += 1;
            }
            v += 1;
            hor = 1;
            col += 1;   
        }
        cout << endl;
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