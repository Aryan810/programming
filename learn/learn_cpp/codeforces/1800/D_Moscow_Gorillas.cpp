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

    vi p(n);
    rep(i, n) cin >> p[i];

    vi q(n);
    rep(i, n) cin >> q[i];

    vector<pi> ranges(n+1, {-1, -1});

    for (int i=0;i<n;i++){
        ranges[p[i]].first = i;
    }

    for (int i=0;i<n;i++){
        ranges[q[i]].second = i;
    }

    for (int i=1;i<=n;i++){
        if (ranges[i].first > ranges[i].second){
            swap(ranges[i].first, ranges[i].second);
        }
    }

    int l = -1; // current range we are required to have.
    int h = -1;
    int ans = 1;
    for (int i=1;i<=n;i++){
        auto curr = ranges[i];
        int f = curr.first;
        int s = curr.second;
        if (l == -1 && h == -1){ // not required to have any.
            int right = n-1-curr.second;
            int left = curr.first;
            int mid = curr.second - curr.first - 1;
            ans += (right * (right+1))/2 + (left * (left + 1))/2 + (mid * (mid + 1))/2;
            l = curr.first;
            h = curr.second;
            continue;
        }

        if (((f >= l && f <= h) || (s >= l && s <= h))){
            l = min(f, l);
            h = max(s, h);
            continue;
        }
        if (f > h){
            int x = (f - h);
            int y = l + 1;
            ans += x*y;
        }else if (s < l){
            int x = l - s;
            int y = n - h;
            ans += x*y;
        }else{
            int x = s - h;
            int y = l - f;
            ans += x*y;
        }
        l = min(f, l);
        h = max(s, h);
    }
    cout << ans << endl;

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