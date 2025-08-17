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
bool check(int ind1, int nor, vi & a){
    int n = a.size();
    int curr = ind1;
    int lst = -1;
    for (int i=0;i<n;i++){
        if (lst == -1){
            lst = a[curr];
            curr = (curr + ((nor)?1:-1) + n)%n;
            continue;
        }
        if (a[curr] < lst){
            return 0;
        }
        lst = a[curr];
        curr = (curr + ((nor)?1:-1) + n)%n;
    }
    return 1;
}

int findans(int ind, int nor, int & n){
    int ans = 1e18;
    if (nor){
        ans = min(ind + ((ind > 0)?2:0), n - ind);
    }else{
        ans = min(n-ind, ind + 2);
    }
    return ans;
}

void solve(){
    
    int n;
    cin >> n;

    vi a(n);
    int mn = 1e18;
    int mx = 0;
    rep(i, n){
        int x;
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
        a[i] = x;
    }
    if (mx == mn){
        cout << 0 << endl;return;
    }
    int ind1 = -1;
    int ind2 = -1;
    bool found = 0;
    for (int i=0;i<n;i++){
        if (a[i] == mn && a[(i+1)%n] == mx){
            found = 1;
            ind1 = i;
        }
        
        if (a[i] == mn && a[(i-1+n)%n] == mx){
            ind2 = i;
            found = 1;
        }
    }
    if (!found){
        cout << -1 << endl;return;
    }
    // cout << ind1 << " " << ind2 <<  << endl;
    if ((ind1 != -1 && check(ind1, 0, a)) && (ind2 != -1 && check(ind2, 1, a))){
        cout << min(findans(ind1, 0, n), findans(ind2, 1, n)) << endl;
    }else if ((ind1 != -1 && check(ind1, 0, a))){
        cout << findans(ind1, 0, n) << endl;
    }else if ((ind2 != -1 && check(ind2, 1, a))){
        cout << findans(ind2, 1, n) << endl;
    }else{
        cout << -1 << endl;return;
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