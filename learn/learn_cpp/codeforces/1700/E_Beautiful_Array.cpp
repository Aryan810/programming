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

    vi a(n);
    map<int, int> cnt;
    rep(i, n){
        int x;
        cin >> x;
        cnt[x] += 1;
        a[i] = x;
    }

    sort(all(a));


    map<int,vector<int> > mp;
    for (auto & ele: cnt){
        if ((ele.second + 1)&1){continue;}
        // cout << ele.first << " " << ele.second << endl;
        mp[ele.first%k].push_back(ele.first/k);
    }
    int ans = 0;
    int odds = 0;
    for (auto & ele: mp){
        
        auto & b = ele.second;
        // for (auto & ele: b){
        //     cout << ele << " ";
        // }cout << endl;
        int m = b.size();
        if (m&1){
            if (odds >= 1){
                cout << -1 << endl;return;
            }
            odds += 1;
            int tmp = 1e18;
            vi e(m+1);
            vi o(m+1);
            e[0] = 0;
            o[0] = 0;
            int se = 0;
            int so = 0;
            for (int i=0;i<m;i++){
                if (i&1){
                    so += b[i];
                }else{
                    se += b[i];
                }
                o[i+1] = so;
                e[i+1] = se;
            }

            for (int i=0;i<m;i+=2){
                int rs = abs((o[m] - o[i+1]) - (e[m]-e[i+1]));
                int ls = abs((o[i]-o[0]) - (e[i]-e[0]));
                // cout << i << " " << rs+ls << endl;
                tmp = min(tmp, rs+ls);
            }
            // cout << tmp << endl;
            ans += tmp;
        }else{
            for (int i=0;i<(m-1);i+=2){
                ans += abs(b[i]-b[i+1]);
            }
        }
    }
    if (odds < 2){cout << ans << endl;}else{
        cout << -1 << endl;
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