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
    int out = 0;

    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            string tmp;
            for (int k=i;k<=j;k++){
                tmp.push_back(s[k]);
            }
            int cons = 0;
            int m = tmp.size();
            int curr = 0;
            int ans = 0;
            // cout << tmp << endl;
            for (int k=0;k<m;k++){
                // cout << curr << " ";
                // if (tmp[k]=='1'){curr += 1;}
                // else{
                //     ans += curr/2;
                //     curr = 0;
                // }
                // bool incconc = 0;
                // if (k == 0){
                //     if (tmp[k] == '1' && (k == m-1 || tmp[k+1] == '0')){
                //         incconc = 1;
                //         cons += 1;
                //     }
                // }else if (k == m-1){
                //     if (tmp[k] == '1' && (k == 0 || tmp[k-1] == '0')){
                //         incconc = 1;
                //         cons += 1;
                //     }
                // }else{
                //     if (tmp[k] == '1' && (tmp[k+1]=='0' && tmp[k-1]=='0')){
                //         incconc = 1;
                //         cons += 1;
                //     }
                // }
                // if (!incconc && cons > 0){
                //     ans += max(1ll, cons-1);
                //     cons = 0;
                // }


                if (tmp[k] == '1'){
                    ans += 1;
                    k += 2;
                }
            }
            // cout << endl;
            // ans += curr/2;
            // if (cons > 0){
            //     ans += max(1ll, cons-1);
            // }
            // cout << tmp << " " << ans << endl;
            out += ans;
        }
    }
    cout << out << endl;

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