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
    
    int n, k;
    cin >> n >> k;

    vi a(n);
    rep(i, n) cin >> a[i];
    bool pal = 1;
    for (int i=0;i<(n/2);i++){
        if (a[i] != a[n-1-i]){
            pal = 0;
            break;
        }
    }
    if (k == 1 || pal){
        cout << "YES" << endl;return;
    }
    vector<pi> b(n);
    rep(i, n){
        b[i] = {a[i], i};
    }
    sort(all(b));
    vector<int> rt;
    vector<int> rem;
    int req = 0;
    for (int i=0;i<k-1;i++){
        if (b[i].first != b[k-1].first){
            rt.push_back(b[i].second);
        }else{
            req += 1;
        }
    }
    
    sort(all(rt));
    for (int i=0;i<n;i++){
        if (b[i].first == b[k-1].first){
            rem.push_back(b[i].second);
        }
    }
    sort(all(rem));
    // for (auto & ele: rt){
    //     cout << ele << " ";
    // }cout << endl;
    for (int i=0;i<(rt.size()/2);i++){
        if (a[rt[i]] != a[rt[rt.size()-1-i]]){
            cout << "NO" << endl;return;
        }
    }

    if (req == 0 || rt.size() == 0){
        cout << "YES" << endl;return;
    }
    // if (rem.size() == 1){cout << "NO" << endl;return;}
    int f = 0;
    int s = rt.size()-1;
    int i = 0;
    int j = rem.size()-1;
    // cout << f << " " << s << endl;
    // cout << req << endl;
    while ((i <= j) && (req > 0 && (s - f >= -1))){
        // cout << i << " " << j << " " << f << " " << s << endl;
        if (s >= f){
            while ((i < rem.size() && j >= 0) && (i < j && (rem[i] < rt[f] && rem[j] > rt[s]))){
                i += 1;
                j -= 1;
                req -= 2;
            }
        }else{
            while ((i < rem.size() && j >= 0) && (i <= j && (rem[i] < rt[f] && rem[i] > rt[s]))){
                i += 1;
                req -= 1;
            }
        }

        while (i < rem.size() && rem[i] < rt[f]){
            i += 1;
        }
        while (j >= 0 && rem[j] > rt[s]){
            j -= 1;
        }
        // cout << i << " " << j << endl;
        f += 1;
        s -= 1;
    }
    if (req > 0){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
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