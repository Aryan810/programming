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

void solve(){
    
    int n;
    cin >> n;
    string s;
    cin >> s;

    int one = 0;
    for (int i=0;i<n;i++){
        one += s[i]-'0';
    }
    int zero = n - one;

    if (one == 0 || zero == 0){
        cout << n << endl;return;
    }else if (zero == 1 || one == 1){
        if (one == 1){
            if (s[0]=='0'&&s[n-1]=='0'){
                cout << n-1 << endl;return;
            }else{
                cout << n << endl;return;
            }
        }else{
            if (s[0]=='1'&&s[n-1]=='1'){
                cout << n-1 << endl;return;
            }else{
                cout << n << endl;return;
            }
        }
    }


    if (s[0] == s[n-1]){
        int f = 0;
        int l = n-1;
        while (s[f] == s[0]){
            f += 1;
        }
        while (s[l] == s[n-1]){
            l -= 1;
        }
        cout << n - (l - f + 1) << endl;
    }else{
        int f = 0;
        int l = n-1;
        while (s[f] == s[0]){
            f += 1;
        }
        while (s[l] == s[n-1]){
            l -= 1;
        }
        cout << n - max(0ll, (l - f)) << endl;
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