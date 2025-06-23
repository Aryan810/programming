// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>
const int M = 1e9 + 7;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){
    
    int w, h, a, b;
    cin >> w >> h >> a >> b;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int poss = 0;
    if (x1 > x2){
        if (y1 > y2){
            int gx = x1 - a - x2;
            int gy = y1 - b - y2;
            if (gx >= 0){
                if (gx%a == 0){
                    poss = 1;
                }
            }
            if (gy >= 0){
                if (gy%b == 0){
                    poss = 1;
                }
            }
        }else{
            int gx = x1 - a - x2;
            int gy = y2 - b - y1;
            if (gx >= 0){
                if (gx%a == 0){
                    poss = 1;
                }
            }
            if (gy >= 0){
                if (gy%b == 0){
                    poss = 1;
                }
            }
        }
    }else{
        if (y1 > y2){
            int gx = x2 - a - x1;
            int gy = y1 - b - y2;
            if (gx >= 0){
                if (gx%a == 0){
                    poss = 1;
                }
            }
            if (gy >= 0){
                if (gy%b == 0){
                    poss = 1;
                }
            }
        }else{
            int gx = x2 - a - x1;
            int gy = y2 - b - y1;
            // cout << gx << " " << gy << endl;
            if (gx >= 0){
                if (gx%a == 0){
                    poss = 1;
                }
            }
            if (gy >= 0){
                if (gy%b == 0){
                    poss = 1;
                }
            }
        }
    }
    cout << (poss?"Yes":"No") << endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}