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
const int m = 3;
template<typename T>
T euclid(T x, T y, T &k, T &l) {
    if (x < 0) {
        T g = euclid(-x, y, k, l);
        k = -k;
        return g;
    }
    if (y < 0) {
        T g = euclid(x, -y, k, l);
        l = -l;
        return g;
    }
    if (y == 0) {
        k = 1;
        l = 0;
        return x;
    }
    T g = euclid(y, x % y, l, k);
    l -= k * (x / y);
    return g;
}

uint MOD = mod7;
struct Mint {
    uint x;

    Mint() : x(0) {}
    Mint(ll _x) {
        _x %= MOD;
        if (_x < 0) _x += MOD;
        x = _x;
    }

    Mint& operator += (const Mint &a) {
        x += a.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }
    Mint& operator -= (const Mint &a) {
        x += MOD - a.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }
    Mint& operator *= (const Mint &a) {
        x = (ull)x * a.x % MOD;
        return *this;
    }
    Mint pow(ll pw) const {
        Mint res = 1;
        Mint cur = *this;
        while(pw) {
            if (pw & 1) res *= cur;
            cur *= cur;
            pw >>= 1;
        }
        return res;
    }
    Mint inv() const {
        ll g, k, l;
        g = euclid<ll>(x, MOD, k, l);
        assert(g == 1);
        k %= MOD;
        if (k < 0) k += MOD;
        return k;
    }
    Mint& operator /= (const Mint &a) {
        return *this *= a.inv();
    }
    Mint operator + (const Mint &a) const {
        return Mint(*this) += a;
    }
    Mint operator - (const Mint &a) const {
        return Mint(*this) -= a;
    }
    Mint operator * (const Mint &a) const {
        return Mint(*this) *= a;
    }
    Mint operator / (const Mint &a) const {
        return Mint(*this) /= a;
    }

    bool operator == (const Mint &a) const {
        return x == a.x;
    }
    bool operator != (const Mint &a) const {
        return x != a.x;
    }
    bool operator < (const Mint &a) const {
        return x < a.x;
    }
};

void solve(){
    
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<Mint> pow(n+1, 1);
    Mint tmp = 1;
    for (int i=1;i<=n;i++){
        tmp *= m;
        pow[i] = tmp;
    }

    Mint h1 = 0;
    Mint h2 = 0;
    
    for (int i=0;i<n;i++){
        if ((i/k)&1){
            h1 += pow[i];
        }
    }
    for (int i=0;i<n;i++){
        if ((i/k + 1)&1){
            h2 += pow[i];
        }
    }

    vector<Mint> ph(n), sh(n);

    Mint curr = 0;
    for (int i=0;i<n;i++){
        if (s[i] == '1'){
            curr += pow[i];
        }
        ph[i] = curr;
    }
    curr = 0;
    for (int i=n-1;i>=0;i--){
        if (s[i] == '1'){
            curr += pow[n-1-i];
        }
        sh[i] = curr;
    }
    
    for (int p=0;p<n;p++){
        Mint f;
        if (p == n-1){
            f = sh[0];
        }else{
            f = sh[0] - sh[p+1];
        }
        Mint l = ph[n-1]-ph[p];
        if (p < n-1){l /= pow[p+1];}
        Mint ch = l + f;

        if (ch == h1 || ch == h2){
            cout << p+1 << endl;return;
        }
    }

    cout << -1 << endl;return;

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