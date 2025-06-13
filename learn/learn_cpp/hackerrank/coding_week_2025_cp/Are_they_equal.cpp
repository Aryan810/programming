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
    vi a(n);
    rep(i, n) cin >> a[i];
    for (int i=0;i<n-1;i++){
        if (a[i] != a[i+1]){
            int k = abs(a[i]-a[i+1]);
            if (k&1){
                int f = a[i];
                int s = a[i+1];
                bool poss = 1;
                for (int j=0;j<n;j++){
                    if (a[j] != f){
                        if (abs(a[j]-f) != k){
                            poss = 0;
                            break;
                        }
                    }
                }
                if (poss){
                    cout << k << endl;return;
                }
                poss = 1;
                for (int j=0;j<n;j++){
                    if (a[j] != s){
                        if (abs(a[j]-s) != k){
                            poss = 0;
                            break;
                        }
                    }
                }
                if (poss){
                    cout << k << endl;return;
                }else{
                    cout << -1 << endl;return;
                }
            }else{
                int t = (a[i]+a[i+1])/2;
                bool poss = 1;
                for (int j=0;j<n;j++){
                    if (a[j] != t){
                        if (abs(a[j]-t) != k/2){
                            poss = 0;
                            break;
                        }
                    }
                }
                if (poss){
                    cout << k/2 << endl;return;
                }
                // x
                int f = a[i];
                int s = a[i+1];
                poss = 1;
                for (int j=0;j<n;j++){
                    if (a[j] != f){
                        if (abs(a[j]-f) != k){
                            poss = 0;
                            break;
                        }
                    }
                }
                if (poss){
                    cout << k << endl;return;
                }
                poss = 1;
                for (int j=0;j<n;j++){
                    if (a[j] != s){
                        if (abs(a[j]-s) != k){
                            poss = 0;
                            break;
                        }
                    }
                }
                if (poss){
                    cout << k << endl;return;
                }else{
                    cout << -1 << endl;return;
                }
            }
        }
    }

    cout << 0 << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        solve();
  

    return 0;
}