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
    rep(i, n) cin >> a[i];

    int i = 0;
    vector<int> out(n, -1);
    while (i < n && a[i] == -1){
        i += 1;
    }

    if (i >= n){
        // only has -1.
        int curr = 2;
        bool mult = 1;
        for (int l=0;l<n;l++){
            out[l] = curr;
            if (!mult){curr /= 2;}else{
                curr *= 2;
            }
            mult = 1 - mult;
            cout << out[l] << " ";
        }cout << endl;
        return;
    }else{
        int curr = a[i];
        bool mult = 1;
        for (int l=(i-1);l>=0;l--){

            if (mult){
                curr *= 2;
            }else{
                curr /= 2;
            }
            out[l] = curr;
            mult = 1 - mult;
        }
    }
    int j = i+1;
    while (j < n){
        while (j < n && a[j] == -1){
            j += 1;
        }
        if (j >= n){break;}
        // cout << i << " " << j << endl;
        int im = log2(a[i]);
        int jm = log2(a[j]);
        vi bi(im+1, 0), bj(jm+1, 0);
        for (int l=0;l<=im;l++){
            if ((1ll<<l)&a[i]){
                bi[l] = 1;
            }
        }
        for (int l=0;l<=jm;l++){
            if ((1ll<<l)&a[j]){
                bj[l] = 1;
            }
        }

        int f = im;
        int s = jm;
        while ((f >= 0 && s >= 0) && bi[f] == bj[s]){
            f -= 1;
            s -= 1;
        }
        int req = f + s + 2;
        int have = j - i;
        if (!(have >= req && (have-req)%2 == 0)){
            cout << -1 << endl;return;
        }
        int curr = a[i];
        for (int l=0;l<(f+1);l++){
            curr /= 2;
            out[++i] = curr;
        }
        while (s >= 0){
            if (bj[s]){
                curr = 2*curr + 1;
                out[++i] = curr;
            }else{
                curr = 2 * curr;
                out[++i] = curr;
            }
            // cout << curr << endl;
            s -= 1;
        }
        if (i < j){i += 1;}
        bool mult = 1;
        while (i < j && a[i] == -1){
            if (mult){
                curr *= 2;
            }else{
                curr /= 2;
            }
            out[i++] = curr;
            mult = 1 - mult;
        }
        // cout << "->" << i << " " << j << endl;
        // for (auto & ele: out){
        //     cout << ele << " ";
        // }cout << endl;
        j += 1;
    }


    int curr = a[i];
    i += 1;
    bool mult = 1;
    while (i < n && a[i] == -1){
        if (mult){
            curr *= 2;
        }else{
            curr /= 2;
        }
        out[i] = curr;
        mult = 1 - mult;
        i += 1;
    }
    for (int i=0;i<n;i++){
        if (out[i] == -1){
            out[i] = a[i];
        }
        // cout << out[i] << " ";
    }
    for (int i=0;i<n-1;i++){
        if (out[i+1]/2 != out[i] && out[i]/2 != out[i+1]){
            cout << -1 << endl;return;
        }
    }

    for (int i=0;i<n;i++){
        cout << out[i] << " ";
    }cout << endl;
    
   



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