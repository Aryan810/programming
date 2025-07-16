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
    
    int a, n;
    cin >> a >> n;
    int sz = min((int)(log10(n) + 1), 12ll);
    int mx = 10;
    int lst = 1;
    int ans = 0;
    for (int i=1;i<=sz;i++){
        int isz = (i+1)/2;
        int val = mx;
        if (isz != lst){
            mx *= 10;
            val = mx;
            lst = isz;
        }
        for (int j=(mx/10);j<(mx);j++){
            string tmp = to_string(j);
            int st;
            if (i&1){
                st = isz - 2;
            }else{
                st = isz - 1;
            }
            // if (i == 2){
            //     cout << st << endl;
            //     cout << tmp << endl;
            // }
            while (st >= 0){
                tmp.push_back(tmp[st]);
                st -= 1;
            }
         
            int x = stol(tmp);
            int y = x;
            int curr = 1;
            string t2;
            while (x > 0){
                t2.push_back(char('0' + x%a));
                x /= a;
                curr *= a;
            }
            bool ispal = 1;
            for (int l=0;l<t2.size()/2;l++){
                if (t2[l] != t2[t2.size()-1-l]){
                    ispal = 0;
                    break;
                }
            }
            if (ispal && y <= n){
                // cout << y << " " << t2 << endl;
                ans += y;
            }
        }
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