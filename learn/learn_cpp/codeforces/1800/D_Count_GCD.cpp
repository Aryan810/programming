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
const int M = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void helper(int i, int taken, int pdt, vi & pf, int & ans, int & m){
    if (i >= pf.size()){
        if (taken == 0){return;}
        if (taken&1){
            ans += m/pdt;
        }else{
            ans -= m/pdt;
        }
        return;
    }

    helper(i+1, taken + 1, pdt * pf[i], pf, ans, m);
    helper(i+1, taken, pdt, pf, ans, m);

}

int calc(int f, int m, vi & pf){
    int ans = 0;
    helper(0, 0, 1, pf, ans, m);
    return m - ans;
}

void solve(){
    
    int n, m;
    cin >> n >> m;

    vi a(n);
    rep(i, n) cin >> a[i];

    for (int i=1;i<n;i++){
        if (a[i-1]%a[i] != 0){
            cout << 0 << endl;return;
        }
    }
    
    int ans = 1;

    map<int, int> pf;
    int tmp = a[0];

    while (tmp%2 == 0){
        pf[2] += 1;
        tmp /= 2;
    }
    for (int i=3;i*i<=m;i++){
        while (tmp%i == 0){
            pf[i] += 1;
            tmp /= i;
        }
    }
    if (tmp > 1){
        pf[tmp] += 1;
    }

    for (int i=1;i<n;i++){
        int f = a[i-1]/a[i];
        int tmp = f;
        vi pff;
        for (auto & ele: pf){
            if (ele.second > 0 && tmp%ele.first == 0){
                pff.push_back(ele.first);
                while (tmp%ele.first == 0){
                    tmp /= ele.first;
                    ele.second -= 1;
                }
            }
        }

        int poss = calc(f, m/a[i], pff);
        ans *= poss;
        ans %= M;
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