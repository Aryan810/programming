// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
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

int fcurr(int pos, int & n){
    int curr = 1;
    int add = 10;
    for (int i=0;i<(n-1-pos);i++){
        curr += add;
        add *= 10;
    }
    return curr;
}
int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}
void solve(){
    
    int l, r;
    cin >> l >> r;
    int n = 12;
    string a = to_string(l);
    string b = to_string(r);
    while(a.size() < 12){
        a.insert(a.begin(), '0');
    }
    while (b.size() < 12){
        b.insert(b.begin(), '0');
    }
    int fpos = 0;
    for (int i=0;i<n;i++){
        if (a[i]<b[i]){
            fpos = i;break;
        }
    }
    // first making it to largest place smaller than r.
    int f = n-1;
    int ans = 0;
    while (f > fpos){
        int curr = fcurr(f, n);
        ans += ('9'-a[f])*(curr);
        a[f] = '9';
        ans += curr;
        a[f] = '0';
        f -= 1;
        while (a[f] == '9'){
            a[f] = '0';
            ans += 1;
            f -= 1;
        }
        ans += 1;
        a[f] += 1;
      
    }
    int curr = fcurr(fpos, n);
    // cout << curr << endl;
    int add = binexpiter(10, n-1-fpos);
    for (int i=fpos;i<n;i++){
        ans += curr * (b[i]-a[i]);
        curr -= add;
        add /= 10;
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