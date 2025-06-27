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
int dp[101][200001];
void solve(){
    
    int n;
    cin >> n;
    vi a(n);
    int sm = 0;
    int isodd = 0;
    int oddind = -1;
    int twodivind = -1;
    rep(i, n){
        int x;
        cin >> x;
        sm += x;
        a[i] = x;
        if (x&1){
            isodd = 1;
            oddind = i;
        }
        if ((x/2)&1){
            twodivind = i;
        }
    }
    // cout << sm << endl;
    dp[0][0] = 1;
    dp[0][a[0]] = 1;
    for (int i=1;i<n;i++){
        for (int j=0;j<=sm;j++){
            int temp = 0;
            if (j >= a[i]){
                temp += dp[i-1][j-a[i]];
            }
            temp += dp[i-1][j];
            // if (i == 1 && j == 4){cout << dp[i-1][j-a[i]] << endl;}
            dp[i][j] = temp;
        }
    }
    
    // cout << dp[n-1][sm/2] << endl;
    // for (int i=0;i<n;i++){
    //     for (int j=0;j<=sm;j++){
    //         cout << dp[i][j] << " ";
    //     }cout << endl;
    // }
    if (dp[n-1][sm/2] == 0){
        cout << 0 << endl;return;
    }
    if (sm&1){
        cout << 0 << endl;return;
    }
    if (isodd){
        cout << 1 << endl << oddind+1 << endl;return;
    }
    if ((sm/2)&1){
        cout << 0 << endl;return;
    }
    if (twodivind != -1){
        cout << 1 << endl << twodivind+1 << endl;return;
    }

    int minpow = 1e18;
    int ind = -1;
    for (int i=0;i<n;i++){
        int curr = a[i];
        int temp = 0;
        while ((curr+1)&1){
            curr /= 2;
            temp += 1;
        }
        if (temp < minpow){
            minpow = temp;
            ind = i;
        }
    }

    cout << 1 << endl << ind+1 << endl;




    






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