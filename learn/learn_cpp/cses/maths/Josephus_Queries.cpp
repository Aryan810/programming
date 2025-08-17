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
    
    int n, k;
    cin >> n >> k;
    int curr = n;
    int st = 2;
    int done = 0;
    int val = 2;
    int f = 1;
    int s = 2;
    while (curr > 1){
        int dels = 0;
        
        if (curr&1){
            if (st == 1){
                dels = (curr+1)/2;
            }else{
                dels = curr/2;
            }
        }else{
            dels = curr/2;
        }
        // cout << "DELS: " << dels << endl;
        if (dels + done < k){
            done += dels;
            if (st == 1){
                f = s;
                s = f + val;
            }else{
                s = f + val;
            }
            if (curr&1){
                st = 3 - st;
            }
            curr -= dels;
            val *= 2;
            continue;
        }

        int m = k - done;
        if (st == 1){
            cout << (f + val*(m-1)) << endl;
        }else{
            cout << (s + val*(m-1)) << endl;
        }
        break;
    }
    if (curr == 1){
        // cout << "here" << endl;
        cout << f << endl;
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