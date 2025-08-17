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

uint MOD = 998244353;
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
vvi graph;
vector<int> dp;
vector<array<int, 4> > dta;
int n, m;
map<int, vector<int> > st;
int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = (ans * a)%M;
        }
        a = (a * a)%M;
        b >>= 1;
    }
    return ans;
}
int helper(int pos){
    // cout << pos << endl;
    if (pos > m){
        return 1;
    }

    if (dp[pos] != -1){
        return dp[pos];
    }

    int ret = 0;

    for (auto & ele: st[pos]){
        auto curr = dta[ele];
        // cout << curr[0] << " " << curr[1] << endl;
        int tmp = helper(curr[1]+1);
        tmp %= M;
        tmp *= curr[2];
        tmp %= M;
        tmp *= binexpiter(curr[3]-curr[2], M-2);
        tmp %= M;
        // cout << "TMP: " << tmp << endl;
        ret += tmp;
        ret %= M;
    }

    return dp[pos] = ret;

}


void solve(){
    
    cin >> n >> m;

    dp.assign(m+1, -1);
    dta.resize(n);


    for (int i=0;i<n;i++){
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        dta[i] = {l, r, p, q};
        st[l].push_back(i);
    }

    int tot = 1;
    for (auto & ele: dta){
        tot *= ele[3]-ele[2];
        tot %= M;
        tot *= binexpiter(ele[3], M-2);
        tot %= M;
        // cout << tot << endl;
    }
    // cout << tot << endl;
    tot *= helper(1);
    tot %= M;
    cout << tot << endl;

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