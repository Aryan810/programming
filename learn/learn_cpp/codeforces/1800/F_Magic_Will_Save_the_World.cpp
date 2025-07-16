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

bool check(int mid, int & w, int & f, int & n, vi & s, int & sm, vi & cum){

    if (w*mid > sm || f*mid > sm){
        return 1;
    }

    if (sm > (w+f)*mid){
        return 0;
    }
    int mx = min(w*mid, f*mid);
    int mn = min(sm-w*mid, sm-f*mid);
    int cnt = cum[mx+1]-cum[mn];
    if (cnt > 0){
        return 1;
    }else{
        return 0;
    }
}

void solve(){
    
    int w, f;
    cin >> w >> f;
    int n;
    cin >> n;
    int sm = 0;
    vi s(n);

    rep(i, n){
        int x;
        cin >> x;
        sm += x;
        s[i] = x;
    }
    sort(all(s));
    vector<int> poss(sm+1, 0);
    poss[0] = 1;
    poss[s[0]] = 1;
    for (int i=1;i<n;i++){
        vi tmp = poss;
        for (int j=0;j<=(sm-s[i]);j++){
            if (poss[j]){
                tmp[j+s[i]] = 1;
            }
        }
        poss = tmp;
    }

    vector<int> cum(sm+2, 0);
    cum[0] = 0;
    int tot = 0;
    for (int j=0;j<=sm;j++){
        tot += poss[j];
        cum[j+1] = tot;
    }

    int l = 1;
    int h = 1e6;

    while (h - l > 1){
        int mid = (h + l)/2;
        // cout << l << " " << h << endl;
        if (check(mid, w, f, n, s, sm, cum)){
            h = mid;
        }else{
            l = mid + 1;
        }
    }
    // cout << l << " " << h << endl;
    if (check(l, w, f, n, s, sm, cum)){
        cout << l << endl;
    }else{
        cout << h << endl;
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