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
vector<vector<int> > visited;
int bfs(pair<int, int> start, pair<int, int> dest){
    queue<pair<pair<int, int>, int> > q;
    q.push({start, 0});
    int ans = 0;
    while (q.size() > 0){
        auto curr = q.front();
        int currLevel = curr.second;
        visited[curr.first.first][curr.first.second] = 1;
        if (curr.first == dest){
            return curr.second;
        }
        int x = curr.first.first;
        int y = curr.first.second;
        vector<pair<pair<int, int>, int> > children;
        children.push_back({{x+2, y-1}, currLevel+1});
        children.push_back({{x+2, y+1}, currLevel+1});
        children.push_back({{x-2, y-1}, currLevel+1});
        children.push_back({{x-2, y+1}, currLevel+1});
        children.push_back({{x-1, y-2}, currLevel+1});
        children.push_back({{x+1, y-2}, currLevel+1});
        children.push_back({{x-1, y+2}, currLevel+1});
        children.push_back({{x+1, y+2}, currLevel+1});

        for (auto ele: children){
            if (!((ele.first.first >= 0 && ele.first.first < 8) && (ele.first.second >= 0 && ele.first.second < 8))){
                continue;
            }
            if (!visited[ele.first.first][ele.first.second]){
                q.push(ele);
            }
        }
        q.pop();
    }
    return ans;
}

void solve(){

    string f, l;
    cin >> f >> l;
    visited.clear();
    visited.assign(9, vector<int>(9, 0));
    pair<int, int> start = {f[0]-'a', f[1]-'1'};
    pair<int, int> dest = {l[0]-'a', l[1]-'1'};
    int ans = bfs(start, dest);
    cout << ans << endl;

    

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