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
vector<pi> poss = {
    {0, 2}, {1, 0}, {2, 1}, {0, 0}, {1, 1}, {2, 2}
};
int mx = 0;
// int cnt = 0;
void helper(set<pi> left, array<int, 3> aa, array<int, 3> bb, int num){
    // cnt += 1;
    if (left.size() == 0){
        mx = max(mx, num);
        // if (num > 200){cout << num << endl;}
        return;
    }
    for (auto & ele: left){
        auto a = aa;
        auto b = bb;
        int tmp = min(a[ele.first], b[ele.second]);
        if (a[ele.first] > b[ele.second]){
            a[ele.first] -= b[ele.second];
            b[ele.second] = 0;
        }else{
            b[ele.second] -= a[ele.first];
            a[ele.first] = 0;
        }
        auto leftx = left;
        leftx.erase(ele);
        helper(leftx, a, b, num+tmp);
    }
}

void solve(){
    
    int n;
    cin >> n;

    array<int, 3> a;
    cin >> a[0] >> a[1] >> a[2];
    array<int, 3> b;
    cin >> b[0] >> b[1] >> b[2];
    set<pi> st;
    for (auto & ele: poss){
        st.insert(ele);
    }
    int f = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
    helper(st, a, b, 0);
    // cout << "MX: " << mx << endl;
    int s = n - mx;
    cout << s << " " << f << endl;
    // cout << cnt << endl;
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