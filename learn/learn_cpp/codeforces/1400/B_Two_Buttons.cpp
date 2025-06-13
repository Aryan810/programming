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

int bfs(int n, int m){
    queue<int> q;
    vector<int> vis(1e5, 0);
    vector<int> lev(1e5, 0);
    q.push(n);
    while (q.size() > 0){
        int curr = q.front();q.pop();
        vis[curr] = 1;
        if (curr == m){
            return lev[curr];
        }
        int c1 = curr - 1;
        int c2 = 2*curr;
        if (c1 >= 0 && c1 <= 1e4+2){
            if (!vis[c1]){
                q.push(c1);
                lev[c1] = lev[curr] + 1;
            }
        }
        if (c2 >= 0 && c2 <= 1e4+2){
            if (!vis[c2]){
                q.push(c2);
                lev[c2] = lev[curr] + 1;
            }
        }
    }
    return 0;
}


void solve(){

    int n, m;
    cin >> n >> m;
    cout << bfs(n, m) << endl;
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int test;
    // cin >> test;

    // while(test--){
        solve();
    // }

    return 0;
}