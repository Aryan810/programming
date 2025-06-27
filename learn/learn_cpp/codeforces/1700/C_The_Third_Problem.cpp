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
const int M = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
const int N = 1e5+1;
int fac[N];
int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = (ans * a)%M;
        }
        a = (a * a)%M;
        b >>= 1;
    }
    return max(ans, 0ll);
}
int ncr(int n, int r){
    if (n <= 0){
        return 1;
    }
    int ans = fac[n];
    ans *= binexpiter(fac[n-r], M-2);
    ans %= M;
    return ans;
}

void solve(){
    
    int n;
    cin >> n;
    
    vi a(n);
    vector<int> pos(n+1);

    rep(i, n){
        int x;
        cin >> x;
        pos[x] = i;
        a[i] = x;
    }

    int rem = 0;
    int ans = 1;
    int l = pos[0];
    int h = pos[0];
    int mx = 1;
    set<int> s;
    int midele = 0;
    for (int i=1;i<n;i++){
        // cout << l << " " << h << endl;
        // cout << midele << " - " << rem << endl;
        int p = pos[i];
        if (p >= l && p <= h){
            midele += 1;
        }else{
            ans *= ncr(rem, midele);
            ans %= M;
            midele = 0;
            if (p > h){
                h = p;
            }else if (p < l){
                l = p;
            }
            rem = h-l-i;
        }
    }
    if (midele > 0){
        ans *= ncr(rem, midele);
        ans %= M;
    }

    cout << ans << endl;

    // while (l > 0 || h < n-1){
    //     // cout << l << " " << h << " " << mx << endl;
    //     if (mx == n){
    //         break;
    //     }
    //     int nxt = pos[mx];
    //     if (nxt <= h && nxt >= l){
    //         mx += 1;
    //         continue;
    //     }
    //     set<int> st;
    //     if (nxt > h){
    //         for (int i=nxt;i>h;i--){
    //             st.insert(a[i]);
    //             s.insert(a[i]);
    //         }
    //         int ini = mx;
    //         for (auto & ele: st){
    //             if (ele == mx){
    //                 mx += 1;
    //             }else{
    //                 break;
    //             }
    //         }
    //         for (int i=ini;i<mx;i++){
    //             if (s.find(i) != s.end()){
    //                 s.erase(i);
    //             }
    //         }
    //         ans *= ncr(abs(nxt-h) - 1, mx-ini-1);
    //         ans %= M;
    //         rem += abs(nxt-h) - (mx-ini);
    //         h = nxt;
    //     }else if (nxt < l){
    //         for (int i=nxt;i<l;i++){
    //             st.insert(a[i]);
    //             s.insert(a[i]);
    //         }
    //         int ini = mx;
    //         for (auto & ele: st){
    //             if (ele == mx){
    //                 mx += 1;
    //             }else{
    //                 break;
    //             }
    //         }
    //         for (int i=ini;i<mx;i++){
    //             if (s.find(i) != s.end()){
    //                 s.erase(i);
    //             }
    //         }
    //         ans *= ncr(abs(nxt-l)-1, mx-ini-1);
    //         ans %= M;
    //         rem += abs(nxt-l) - (mx-ini);
    //         l = nxt;
    //     }
    //     for (auto & ele: s){
    //         if (ele == mx){
    //             mx += 1;
    //         }else{
    //             break;
    //         }
    //     }
    // }
    // cout << rem << endl;
    // cout << mx << endl;
    

}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    fac[0] = 1;
    fac[1] = 1;
    for (int i=2;i<N;i++){
        fac[i] = (fac[i-1] * i)%M;
    }
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}