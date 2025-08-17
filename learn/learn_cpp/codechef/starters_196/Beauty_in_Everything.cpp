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

bool check(int mid, int i, int & n, string & s, vi & zind, vi & oind){
    // checking for 1001
    auto fo = lower_bound(all(oind), i);
    auto lo = upper_bound(all(oind), mid);
    // cout << fo-oind.begin() << " " << lo << endl;
    if ((fo != oind.end() && *fo < mid) && (lo != oind.begin() && *(lo-1) > *fo && *(lo-1) <= mid)){
        int l = *fo;
        int h = *(lo-1);
        auto it1 = upper_bound(all(zind), l);
        if (it1 != zind.end() && *it1 < h){
            auto it2 = it1 + 1;
            if (it2 != zind.end() && *it2 > *it1 && *it2 < h){
                return 1;
            }
        }
    }

    // checking for 0110
    auto fz = lower_bound(all(zind), i);
    auto lz = upper_bound(all(zind), mid);
    if ((fz != zind.end() && *fz < mid) && (lz != zind.begin() && *(lz-1) > *fz && *(lz-1) <= mid)){
        int l = *fz;
        int h = *(lz-1);
        auto it1 = upper_bound(all(oind), l);
        if (it1 != oind.end() && *it1 < h){
            auto it2 = it1 + 1;
            if (it2 != oind.end() && *it2 > *it1 && *it2 < h){
                return 1;
            }
        }
    }

    // checking for 1100
    fo = lower_bound(all(oind), i);
    if ((fo != oind.end() && (fo+1) != oind.end()) && *(fo+1) <= mid){
        int s1 = *(fo+1);
        auto it1 = upper_bound(all(zind), s1);
        if ((it1 != zind.end() && (it1+1) != zind.end()) && *(it1+1) <= mid){
            return 1;
        }
    }

    // checking for 0011
    fz = lower_bound(all(zind), i);
    if ((fz != zind.end() && (fz+1) != zind.end()) && *(fz+1) <= mid){
        int s1 = *(fz+1);
        auto it1 = upper_bound(all(oind), s1);
        if ((it1 != oind.end() && (it1+1) != oind.end()) && *(it1+1) <= mid){
            return 1;
        }
    }
    return 0;
}

void solve(){
    
    int n;
    cin >> n;

    string s;
    cin >> s;
    if (n <= 3){
        cout << n << endl;return;
    }
    vi oind;
    vi zind;

    for (int i=0;i<n;i++){
        if (s[i]=='0'){
            zind.push_back(i);
        }else{
            oind.push_back(i);
        }
    }
    // cout << check(3, 0, n, s, zind, oind) << endl;
    int ans = 3;
    for (int i=0;i<=(n-4);i++){
        int l = i + 2;
        int h = n-1;
        while (h - l > 1){
            int mid = (h + l)/2;
            if (check(mid, i, n, s, zind, oind)){
                h = mid - 1;
            }else{
                l = mid;
            }
        }
        if (!check(h, i, n, s, zind, oind)){
            ans = max(ans, h-i+1);
        }else{
            ans = max(ans, l-i+1);
        }
        // cout << i << " " << ans << endl;
    }
    cout << ans << endl;

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