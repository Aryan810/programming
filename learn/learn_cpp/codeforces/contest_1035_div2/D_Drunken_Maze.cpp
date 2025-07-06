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

void bfs(vector<vector<char> > & grid, int & n, int & m, pi & st, pi & en){
    queue<array<int, 5> > q;
    q.push({st.first, st.second, 0, 0, 0}); // i, j, lev, dis, dir.
    // 0 - right, 1 - left, 2 - top, 3 - bottom.
    vvi lev(n, vector<int>(m, 1e12));
    lev[st.first][st.second] = 0;
    vector<pi> poss = {
        {0, 1}, {0, -1}, {-1, 0}, {1, 0}
    };
    while (q.size() > 0){
        auto curr = q.front();
        // cout << curr[0] << " " << curr[1] << " " << curr[2] << endl;
        q.pop();
        if (curr[3] == 3){
            for (int i=0;i<4;i++){
                // if (i != curr[4]){
                    pi nxt = {poss[i].first + curr[0], poss[i].second + curr[1]};
                    if (grid[nxt.first][nxt.second] != '#'){
                        if (curr[4] == i){
                            if (lev[nxt.first][nxt.second] > curr[2] + 3){
                                q.push({nxt.first, nxt.second, curr[2] + 3, 2, i});
                                lev[nxt.first][nxt.second] = min(lev[nxt.first][nxt.second], curr[2] + 3);
                            }
                        }else{
                            if (lev[nxt.first][nxt.second] > curr[2] + 1){
                                q.push({nxt.first, nxt.second, curr[2] + 1, 1, i});
                                lev[nxt.first][nxt.second] = min(lev[nxt.first][nxt.second], curr[2] + 1);
                            }
                        }
                    }
                // }
            }
        }else{
            for (int i=0;i<4;i++){
                pi nxt = {poss[i].first + curr[0], poss[i].second + curr[1]};
                if (grid[nxt.first][nxt.second] != '#'){
                    if (curr[4] == i){
                        if (lev[nxt.first][nxt.second] > curr[2] + 1){
                            q.push({nxt.first, nxt.second, curr[2] + 1, curr[3] + 1, i});
                            lev[nxt.first][nxt.second] = min(lev[nxt.first][nxt.second], curr[2] + 1);
                        }
                    }else{
                       if (lev[nxt.first][nxt.second] > curr[2] + 1){
                            q.push({nxt.first, nxt.second, curr[2] + 1, 1, i});
                            lev[nxt.first][nxt.second] = min(lev[nxt.first][nxt.second], curr[2] + 1);
                        }
                    }
                }
            }
        }
    }

    cout << ((lev[en.first][en.second] == (int)(1e12))?-1:lev[en.first][en.second]) << endl;
}

void solve(){
    
    int n, m;
    cin >> n >> m;

    vector<vector<char> > grid(n, vector<char>(m));
    pi st, en;
    rep(i, n){
        rep(j, m){
            char c;
            cin >> c;
            if (c == 'S'){
                st = {i, j};
            }else if (c == 'T'){
                en = {i, j};
            }
            grid[i][j] = c;
        }
    }

    bfs(grid, n, m, st, en);
    


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