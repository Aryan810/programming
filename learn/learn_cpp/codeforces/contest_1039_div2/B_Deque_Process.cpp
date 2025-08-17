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

    vi a(n);
    rep(i, n) cin >> a[i];

    string out;

    int curr = 0;
    int inc = 0;

    vector<int> q;

    int l = 0;
    int h = n-1;
    while (l <= h){
        // cout << l << " " << h << endl;
        if (l == h){
            out.push_back('L');
            q.push_back(a[l]);
            break;
        }
        int f = a[l];
        int s = a[h];
        if (curr < 2){
            out.push_back('L');
            if (curr == 1){
                if (a[l] > q.back()){
                    inc = 1;
                }else{
                    inc = 0;
                }
            }
            curr += 1;
            q.push_back(a[l]);
            l += 1;
            continue;
        }

        if (inc){
            if (f < s){
                out.push_back('R');
                out.push_back('L');
                if (q.back() > s){
                    curr = 3;
                    inc = 0;
                }else{
                    curr = 2;
                    inc = 0;
                }
                q.push_back(s);
                q.push_back(f);
            }else{
                out.push_back('L');
                out.push_back('R');
                if (q.back() > f){
                    curr = 3;
                    inc = 0;
                }else{
                    curr = 2;
                    inc = 0;
                }
                q.push_back(f);
                q.push_back(s);
            }
        }else{
            if (f < s){
                out.push_back('L');
                out.push_back('R');
                if (q.back() < f){
                    curr = 3;
                    inc = 1;
                }else{
                    curr = 2;
                    inc = 1;
                }
                q.push_back(f);
                q.push_back(s);
            }else{
                out.push_back('R');
                out.push_back('L');
                if (q.back() < s){
                    curr = 3;
                    inc = 1;
                }else{
                    curr = 2;
                    inc = 1;
                }
                q.push_back(s);
                q.push_back(f);
            }
        }
        l += 1;
        h -= 1;
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