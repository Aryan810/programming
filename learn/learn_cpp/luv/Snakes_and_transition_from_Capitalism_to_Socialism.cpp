#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>
#define INF 1e9+7
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
vector<vector<int> > visited;
vector<vector<int> > level;
int bfs(vector<vector<int> > & grid, int mx){
    // cout << mx << endl;
    queue<pair<int, int> > q;
    for (int i=0;i<grid.size();i++){
        for (int j=0;j<grid[i].size();j++){
            if (grid[i][j] == mx){
                q.push({i, j});
                level[i][j] = 0;
            }
        }
    }
    while (q.size() > 0){
        auto curr = q.front();
        int x = curr.first;
        int y = curr.second;
        // visited[x][y] = 1;
        vector<pair<int, int> > children = {
            {x+1, y}, {x-1, y}, {x, y-1}, {x, y+1}, {x-1, y-1}, {x+1, y+1}, {x-1, y+1}, {x+1, y-1}
        };
        for (auto ele: children){
            if (!((ele.first < grid.size() && ele.first >= 0) && (ele.second < grid[0].size() && ele.second >= 0))){continue;}
            if (grid[ele.first][ele.second] < mx){
                if (level[x][y] + 1 < level[ele.first][ele.second]){
                    q.push(ele);
                    level[ele.first][ele.second] = level[x][y] + 1;
                }
            }
        }
        q.pop();
    }
    int ans = 0;
    for (auto e1: level){
        for (auto ele: e1){
            ans = max(ans, ele);
            // cout << ele << " ";
        }
        // cout << endl;
    }

    return ans;
}

void solve(){

    int n, m;
    cin >> n >> m;
    level.clear();
    visited.clear();
    level.assign(n, vector<int>(m, INF));
    visited.assign(n, vector<int>(m, 0));
    vector<vector<int> > grid(n, vector<int>(m));
    int mx = 0;
    rep(i, n){
        rep(j, m){
            int x;
            cin >> x;
            mx = max(mx, x);
            grid[i][j] = x;
        }
    }

    cout << bfs(grid, mx) << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}