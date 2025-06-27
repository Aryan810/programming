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

void solve(){
    
    int n, q;
    cin >> n >> q;
    vi a(n);
    rep(i, n) cin >> a[i];

    int ts = accumulate(all(a), 0ll);
    set<int> oind;
    for (int i=0;i<n;i++){
        if (a[i] == 1){
            oind.insert(i);
        }
    }

    for (int i=0;i<q;i++){
        int op;
        cin >> op;
        if (op == 1){
            int s;
            cin >> s;
            int fo;
            if (oind.size() > 0){fo = *oind.begin();}else{
                fo = n;
            }
            // cout << fo << endl;
            int l = 1;
            int h = ts - 2*fo;
            // int mx = max(max(ts-2*fo, 2*fo+1), max())
            if (fo < n){
                if ((s >= l && s <=h) || (s >= 1 && s <= 2*fo+1)){
                    cout << "YES" << endl;
                    continue;
                }
            }
            if ((s-h)%2 == 0 && s-h <= 2*fo){
                cout << "YES" << endl; 
            }else if (oind.size() > 1){
                int lo;
                lo = *(--oind.end());

                int ll = 1;
                int hh = ts - 2*(n - lo - 1);
                if ((s >= ll && s <=hh) || (s >= 1 && s <= 2*(n-lo-1)+1)){
                    cout << "YES" << endl;
                    continue;
                }
                if ((s-hh)%2 == 0 && s-hh <= 2*(n-lo-1)){
                    cout << "YES" << endl;
                }else{
                    cout << "NO" << endl;
                }
            }else{
                cout << "NO" << endl;
            }
        }else{
            int ind, v;
            cin >> ind >> v;
            ind--;
            int fo;
            if (oind.size() > 0){fo = *oind.begin();}else{
                fo = n;
            }
            if (v == 2){
                if (a[ind] == 1){
                    oind.erase(ind);
                }
                ts += v-a[ind];
                a[ind] = v;
            }else{
                ts += v - a[ind];
                oind.insert(ind);
                a[ind] = v;
            }
        }
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