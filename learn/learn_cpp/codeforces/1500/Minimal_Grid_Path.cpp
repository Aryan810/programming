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
    
    int n;
    cin >> n;

    vector<vector<char> > grid(n, vector<char>(n));
    rep(i, n){
        string s;
        cin >> s;
        rep(j, n){
            grid[i][j] = s[j];
        }
    }

    vvi vis(n, vector<int>(n, 0));
    string out(2*n-1, 'Z');
    out[0] = grid[0][0];
    queue<pi> head;
    head.push({0, 0});
    vector<vector<int> > lev(n, vector<int>(n, 0));
    while (head.size() > 0){
        vector<pi> samelev;
        int mn = 1e18;
        while (head.size() > 0){
            // cout << "Here" << endl;
            auto curr = head.front();
            // cout << curr.first << " " << curr.second << endl;
            head.pop();

            vector<pi> poss = {
                {1, 0}, {0, 1}
            };
            for (auto & ele: poss){
                if (((curr.first + ele.first) < n) && ((curr.second + ele.second) < n)){
                    mn = min(mn, (int)grid[curr.first+ele.first][curr.second + ele.second]);
                }
            }
            for (auto & ele: poss){
                if (((curr.first + ele.first) < n) && ((curr.second + ele.second) < n)){
                    if ((int)grid[curr.first+ele.first][curr.second + ele.second] == mn){
                        pi x = {curr.first + ele.first, curr.second + ele.second};
                        if (!vis[x.first][x.second]){
                            lev[x.first][x.second] = lev[curr.first][curr.second] + 1;
                            out[lev[x.first][x.second]] = min(out[lev[x.first][x.second]], (char)mn);
                            vis[x.first][x.second] = 1;
                            samelev.push_back(x);
                        }
                    }
                }
            }
        }
        if (mn == 1e18){break;}
        for (auto & ele: samelev){
            if ((char)mn == grid[ele.first][ele.second]){
                head.push(ele);
            }
        }
    }

    cout << out << endl;
    







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