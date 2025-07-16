// #include<atcoder/modint>
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
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

pair< vector<int>, pi> func(int x){
    if (x <= 1){
        vi tmp = {};
        return {tmp, {0, 1}};
    }
    if (x&1){
        auto temp = func(x-1);
        temp.first.push_back(temp.second.first - 1);
        return {temp.first, {mnv(temp.first), mxv(temp.first)}};
    }else{
        auto temp = func(x/2);
        temp.first.push_back(temp.second.second + 1);
        return {temp.first, {mnv(temp.first), mxv(temp.first)}};
    }
}

void solve(){
    
    int x;
    cin >> x;

    vi out = func(x).first;
    cout << out.size() << endl;
    for (auto & ele: out){
        cout << ele << " ";
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