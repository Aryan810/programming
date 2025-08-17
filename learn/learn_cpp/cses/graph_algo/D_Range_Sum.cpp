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

bool check(int b, int & a, int n){
    n -= 1;
    int f = n*a + (n*(n-1))/2 + b;
    int s = n*b - (n * (n - 1))/2 + a;
    int t = (b-a)*(b-a);
    // cout << a << " " << b << " " << f << " " << s << " " << t << endl;
    return (t >= f && t <= s);
}

void solve(){
    
    int n;
    cin >> n;
    if (n == 2){
        cout << "3 1" << endl;return;
    }
    int a=-1, b=-1;
    for (int i=1;i<=n;i++){
        int l = i + n - 1;
        int h = 1e9;
        while (h - l > 1){
            int mid = (h + l)/2;
            // cout << l << " " << h << endl;
            if (check(mid, i, n)){
                l = mid;
            }else{
                h = mid - 1;
            }
        }
        // cout << i << " " << l << " " << h << endl;
        if (check(h, i, n)){
            a = i;
            b = h;
            break;
        }else if (check(l, i, n)){
            a = i;
            b = l;
            break;
        }
    }
    int req = (b-a)*(b-a) - a - b;

    int mn = (n-2)*(a+1) + ((n-2)*(n-3))/2;
    int extra = (req-mn)/(n-2);
    int st = (a+1)+extra;
    extra = n-2 - (req-mn)%(n-2);

    vi out;
    out.push_back(a);

    for (int i=0;i<extra;i++){
        out.push_back(st++);
    }
    st += 1;
    extra = n - 2 - extra;
    for (int i=0;i<(extra);i++){
        out.push_back(st++);
    }
    out.push_back(b);

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