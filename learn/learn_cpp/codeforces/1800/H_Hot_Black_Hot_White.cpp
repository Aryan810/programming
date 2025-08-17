// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
// using namespace atcoder;
// using mint = modint;
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define each(x, a) for (auto &x : a)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pi pair<int, int>
#define p(a, b) pair<a, b>
#define vi vector<int>
#define vii vector<int>::iterator
#define vvi vector<vector<int> >
#define vv(x) vector<vector<x> >
#define PRECISION(x) cout << fixed << setprecision(x);
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define umap(x, y) unordered_map<x, y, custom_hash>
const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){
    
    int n;
    cin >> n;

    vi a(n);
    vi cnt(3, 0);
    vector<vector<int> > ind(3);
    rep(i, n){
        int x;
        cin >> x;
        cnt[(x*x)%3] += 1;
        a[i] = x;
        ind[(x*x)%3].push_back(i);
    }

    int z = cnt[0];
    int o = cnt[1];
    int t = cnt[2];
    int zd = -1;
    vi out(n);
    if (z > n/2){
        if (t != 0 && o != 0){cout << -1 << endl;return;}
        if (t == 0){
            zd = 2;
            for (int i=0;i<n/2;i++){
                out[ind[0][i]] = 0;
            }
            for (int i=n/2;i<ind[0].size();i++){
                out[ind[0][i]] = 1;
            }
            for (int i=0;i<ind[1].size();i++){
                out[ind[1][i]] = 1;
            }
        }else{
            zd = 1;
            for (int i=0;i<n/2;i++){
                out[ind[0][i]] = 0;
            }
            for (int i=n/2;i<ind[0].size();i++){
                out[ind[0][i]] = 1;
            }
            for (int i=0;i<ind[2].size();i++){
                out[ind[2][i]] = 1;
            }
        }
    }else if (z == n/2){
        zd = 0;
        for (int i=0;i<n/2;i++){
            out[ind[0][i]] = 0;
        }
        for (int i=0;i<ind[2].size();i++){
            out[ind[2][i]] = 1;
        }
        for (int i=0;i<ind[1].size();i++){
            out[ind[1][i]] = 1;
        }
    }else{
        if (o > n/2){
            if (t != 0 && z != 0){cout << -1 << endl;return;}
            if (t == 0){
                zd = 0;
                for (int i=0;i<n/2;i++){
                    out[ind[1][i]] = 0;
                }
                for (int i=n/2;i<ind[1].size();i++){
                    out[ind[1][i]] = 1;
                }
                for (int i=0;i<ind[0].size();i++){
                    out[ind[0][i]] = 1;
                }
            }else{
                zd = 1;
                for (int i=0;i<n/2;i++){
                    out[ind[1][i]] = 0;
                }
                for (int i=n/2;i<ind[1].size();i++){
                    out[ind[1][i]] = 1;
                }
                for (int i=0;i<ind[2].size();i++){
                    out[ind[2][i]] = 1;
                }
            }
        }else if (o == n/2){
            zd = 2;
            for (int i=0;i<n/2;i++){
                out[ind[1][i]] = 0;
            }
            for (int i=0;i<ind[2].size();i++){
                out[ind[2][i]] = 1;
            }
            for (int i=0;i<ind[0].size();i++){
                out[ind[0][i]] = 1;
            }
        }else{
            if (t < n/2){cout << -1 << endl;return;}
            if (t == n/2){
                zd = 1;
                for (int i=0;i<n/2;i++){
                    out[ind[2][i]] = 0;
                }
                for (int i=0;i<ind[1].size();i++){
                    out[ind[1][i]] = 1;
                }
                for (int i=0;i<ind[0].size();i++){
                    out[ind[0][i]] = 1;
                } 
            }else{
                if (o != 0 && z != 0){cout << -1 << endl;return;}
                if (o == 0){
                    zd = 2;
                    for (int i=0;i<n/2;i++){
                        out[ind[2][i]] = 0;
                    }
                    for (int i=n/2;i<ind[2].size();i++){
                        out[ind[2][i]] = 1;
                    }
                    for (int i=0;i<ind[1].size();i++){
                        out[ind[1][i]] = 1;
                    }
                }else{
                    zd = 0;
                    for (int i=0;i<n/2;i++){
                        out[ind[2][i]] = 0;
                    }
                    for (int i=n/2;i<ind[2].size();i++){
                        out[ind[2][i]] = 1;
                    }
                    for (int i=0;i<ind[0].size();i++){
                        out[ind[0][i]] = 1;
                    }
                }
            }
        }
    }

    cout << zd << endl;
    for (auto &ele: out){
        cout << ele;
    }cout << endl;

}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test = 1;

    while(test--){
        solve();
    }

    return 0;
}