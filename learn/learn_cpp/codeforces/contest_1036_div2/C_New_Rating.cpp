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

bool check(int mid, vi & a){
    int n = a.size();
    vi r(n+1);
    vi l(n+1);
    l[0] = 0;
    r[n] = mid;
    for (int i=0;i<n;i++){
        int lst = l[i];
        if (lst > a[i]){
            l[i+1] = lst - 1;
        }else if (lst < a[i]){
            l[i+1] = lst + 1;
        }else{
            l[i+1] = lst;
        }
    }
    for (int i=n-1;i>=0;i--){
        int lst = r[i+1];
        if (a[i] < lst){
            r[i] = lst + 1;
        }else if (a[i] >= lst){
            r[i] = lst - 1;
        }
    }
    vector<int> cnt(2*n + 1, 0);
    for (int i=0;i<=n;i++){
        if (r[i] >= 0){cnt[r[i]] += 1;}
    }

    for (int i=0;i<n;i++){
        if (r[i] >= 0){cnt[r[i]] -= 1;}
        if (l[i] >= 0 && cnt[l[i]] > 0){
            return 1;
        }
    }
    return 0;
}

void solve(){
    
    int n;
    cin >> n;

    vi a(n);
    rep(i, n) cin >> a[i];

    int l = 0;
    int h = n-1;

    while (h - l > 1){
        int mid = (h + l)/2;
        if (check(mid, a)){
            l = mid;
        }else{
            h = mid - 1;
        }
    }

    if (check(h, a)){
        cout << h << endl;
    }else{
        cout << l << endl;
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