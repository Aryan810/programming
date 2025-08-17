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
    
    int n, s;
    cin >> n >> s;

    vi a(n);
    int o = 0;
    int z = 0;
    int t = 0;
    rep(i, n){
        int x;
        cin >> x;
        if (x == 1){
            o += 1;
        }else if (x == 0){
            z += 1;
        }else{
            t += 1;
        }
        a[i] = x;
    }

    int sm = accumulate(all(a), 0ll);

    if (s < sm){
        for (int i=0;i<n;i++){
            cout << a[i] << " ";
        }cout << endl;return;
    }

    int diff = s - sm;
    if (diff == 0){
        cout << -1 << endl;return;
    }

    if (z > 0){
        if (o == 0 && t == 0){
            for (int i=0;i<n;i++){
                cout << a[i] << " ";
            }cout << endl;return;
        }else if (o == 0){
            if (diff%2 == 0){
                cout << -1 << endl;return;
            }else{
                for (int i=0;i<n;i++){
                cout << a[i] << " ";
                }cout << endl;return;
            }
        }else if (t == 0){
            cout << -1 << endl;return;
        }else{
            if (diff >= 2){
                cout << -1 << endl;return;
            }else{
                for (int i=0;i<o;i++){
                    cout << "1 ";
                }
                for (int i=0;i<t;i++){
                    cout << "2 ";
                }
                for (int i=0;i<z;i++){
                    cout << "0 ";
                }
                cout << endl;
            }
        }
    }
    else if (o == 0){
        if (diff%4 == 0){
            cout << -1 << endl;return;
        }else{
            for (int i=0;i<n;i++){
                cout << a[i] << " ";
            }cout << endl;return;
        }
    }else if (t == 0){
        if (diff%2 == 0){
            cout << -1 << endl;return;
        }else{
            for (int i=0;i<n;i++){
                cout << a[i] << " ";
            }cout << endl;return;
        }
    }else{
        if (diff%3 == 0){
            cout << -1 << endl;return;
        }
        if (o > t+1){
            if (diff%2 == 0){
                cout << -1 << endl;return;
            }else{
                for (int i=0;i<n;i++){
                    cout << a[i] << " ";
                }cout << endl;return;
            }
        }else if (t > o+1){
            if (diff%4 == 0){
                cout << -1 << endl;return;
            }else{
                for (int i=0;i<n;i++){
                    cout << a[i] << " ";
                }cout << endl;return;
            }
        }else if (o >= t){
            bool one = 1;
            for (int i=0;i<n;i++){
                if (one){
                    cout << "1 ";
                }else{
                    cout << "2 ";
                }
                one = 1 - one;
            }
        }else{
            bool one = 0;
            for (int i=0;i<n;i++){
                if (one){
                    cout << "1 ";
                }else{
                    cout << "2 ";
                }
                one = 1 - one;
            }
        }
    }

}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}