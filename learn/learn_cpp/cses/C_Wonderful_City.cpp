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
int dp[1001][2][2];
const int INF = 1e15;
int helpv(int i, int prev, int normal, vvi & grid, int & n, vi & a){
    if (i >= n){
        return 0;
    }
    if (dp[i][prev][normal] != -1){
        return dp[i][prev][normal];
    }

    int ret = INF;
    bool shouldtakelast = 0;
    bool samewithlast = 0;
    bool samewithnxt = 0;
    bool shouldtakenxt = 0;
    bool shouldtakeiflast = 0;
    for (int j=0;j<n;j++){
        if (i > 0 && grid[i-1][j] == grid[i][j]){
            samewithlast = 1;
        }
        if (i < n-1 && grid[i+1][j] == grid[i][j]){
            samewithnxt = 1;
        }
        if (i > 0 && grid[i-1][j]-grid[i][j] == 1){
            shouldtakelast = 1;
        }
        if (i < n-1 && grid[i+1][j]-grid[i][j] == 1){
            shouldtakenxt = 1;
        }
        if (i > 0 && grid[i][j]-grid[i-1][j] == 1){
            shouldtakeiflast = 1;
        }
    }

    if (!prev){
        if (samewithlast){
            // we should take this.
            if (shouldtakelast){
                ret = INF;
            }else{
                ret = helpv(i+1, 1, 0, grid, n, a) + a[i];
            }
        }else{
            if (samewithnxt){
                ret = min(ret, helpv(i+1, 0, 0, grid, n, a));
                if (!shouldtakelast){
                    ret = min(ret, helpv(i+1, 1, 0, grid, n, a) + a[i]);
                }
            }else{
                ret = min(ret, helpv(i+1, 0, 1, grid, n, a));
                if (!shouldtakelast){
                    ret = min(ret, helpv(i+1, 1, 1, grid, n, a) + a[i]);
                }
            }
        }
    }else{
        if (shouldtakeiflast){
            if (samewithlast){
                ret = INF;
            }else{
                if (samewithnxt){
                    ret = helpv(i+1, 1, 0, grid, n, a) + a[i];
                }else{
                    ret = helpv(i+1, 1, 1, grid, n, a) + a[i];
                }
            }
        }else{
            if (samewithlast){
                // should not take
                ret = helpv(i+1, 0, 0, grid, n, a);
            }else{
                if (samewithnxt){
                    ret = min(ret, helpv(i+1, 0, 0, grid, n, a));
                    ret = min(ret, helpv(i+1, 1, 0, grid, n, a) + a[i]);
                }else{
                    ret = min(ret, helpv(i+1, 0, 1, grid, n, a));
                    ret = min(ret, helpv(i+1, 1, 1, grid, n, a) + a[i]);
                }
            }
        }
    }
    return dp[i][prev][normal] = ret;
}

int helph(int j, int prev, int normal, vvi & grid, int & n, vi & a){
    if (j >= n){
        return 0;
    }
    if (dp[j][prev][normal] != -1){
        return dp[j][prev][normal];
    }

    int ret = INF;
    bool shouldtakelast = 0;
    bool samewithlast = 0;
    bool samewithnxt = 0;
    bool shouldtakenxt = 0;
    bool shouldtakeiflast = 0;
    for (int i=0;i<n;i++){
        // cout << "now" << endl;
        if (j > 0 && grid[i][j-1] == grid[i][j]){
            samewithlast = 1;
        }
        if (j < n-1 && grid[i][j+1] == grid[i][j]){
            samewithnxt = 1;
        }
        if (j > 0 && grid[i][j-1]-grid[i][j] == 1){
            shouldtakelast = 1;
        }
        if (j < n-1 && grid[i][j+1]-grid[i][j] == 1){
            shouldtakenxt = 1;
        }
        if (j > 0 && grid[i][j]-grid[i][j-1] == 1){
            shouldtakeiflast = 1;
        }
    }
    // cout << "here" << endl;
    if (!prev){
        if (samewithlast){
            // we should take this.
            if (shouldtakelast){
                ret = INF;
            }else{
                ret = helph(j+1, 1, 0, grid, n, a) + a[j];
            }
        }else{
            if (samewithnxt){
                ret = min(ret, helph(j+1, 0, 0, grid, n, a));
                if (!shouldtakelast){
                    ret = min(ret, helph(j+1, 1, 0, grid, n, a) + a[j]);
                }
            }else{
                ret = min(ret, helph(j+1, 0, 1, grid, n, a));
                if (!shouldtakelast){
                    ret = min(ret, helph(j+1, 1, 1, grid, n, a) + a[j]);
                }
            }
        }
    }else{
        if (shouldtakeiflast){
            if (samewithlast){
                ret = INF;
            }else{
                if (samewithnxt){
                    ret = helph(j+1, 1, 0, grid, n, a) + a[j];
                }else{
                    ret = helph(j+1, 1, 1, grid, n, a) + a[j];
                }
            }
        }else{
            if (samewithlast){
                // should not take
                ret = helph(j+1, 0, 0, grid, n, a);
            }else{
                if (samewithnxt){
                    ret = min(ret, helph(j+1, 0, 0, grid, n, a));
                    ret = min(ret, helph(j+1, 1, 0, grid, n, a) + a[j]);
                }else{
                    ret = min(ret, helph(j+1, 0, 1, grid, n, a));
                    ret = min(ret, helph(j+1, 1, 1, grid, n, a) + a[j]);
                }
            }
        }
    }
    return dp[j][prev][normal] = ret;
}

void solve(){
    
    int n;
    cin >> n;

    vvi grid(n, vector<int>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }

    vi a(n);
    vi b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];


    memset(dp, -1, sizeof(dp));
    int f = helpv(0, 0, 1, grid, n, a);
    memset(dp, -1, sizeof(dp));
    int s = helph(0, 0, 1, grid, n, b);
    // cout << f + s << endl;
    int ans = f + s;
    if (ans >= 1e14){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
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