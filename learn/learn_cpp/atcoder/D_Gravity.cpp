#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace __gnu_pbds;
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<int>::iterator
#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){

    int n, w;
    cin >> n >> w;
    vector<set<pair<int, int> > > grid(w, set<pair<int, int> >());
    vector<int> dieat(n+1, -1);
    for (int i=0;i<n;i++){
        int x, y;
        cin >> x >> y;
        grid[x-1].insert({y, i+1});
    }

    // int minsz = 1e18;
    // int maxfy = 0;
    // for (int i=0;i<w;i++){
    //     if (grid[i].size() > 0){
    //         maxfy = max(maxfy, grid[i].begin()->first);
    //     }
    //     minsz = min(minsz, (int)grid[i].size());
    // }
    // // cout << maxfy << endl;
    // for (int i=0;i<w;i++){
    //     auto it = grid[i].begin();
    //     for (int j=0;j<minsz;j++){
    //         dieat[it->second] = maxfy + j;
    //         it ++;
    //         // cout << "SET: " << grid[i][j].first << " " << maxfy + j << endl;
    //     }
    //     for (int j=minsz;j<(int)grid[i].size();j++){
    //         dieat[it->second] = -1;
    //         it ++;
    //     }
    // }
    while (1){
        int cnt = 0;
        int mxy = 0;
        vector<int> ind;
        for (int i=0;i<w;i++){
            if (grid[i].size()){
                cnt += 1;
                auto it = grid[i].begin();
                mxy=max(mxy, it->first);
                ind.push_back(it->second);
                grid[i].erase(it);
            }
        }
        if (cnt != w){
            break;
        }
        for (auto ele: ind){
            dieat[ele] = mxy;
        }
    }
    // for (auto ele: dieat){
    //     cout << ele << " ";
    // }cout << endl;
    int q;cin >> q;
    for (int i=0;i<q;i++){
        int t, a;
        cin >> t >> a;
        // cout << dieat[a] << endl;
        if (dieat[a] == -1){
            cout << "Yes" << endl;
        }else{
            if (t >= dieat[a]){
                cout << "No" << endl;
            }else{
                cout << "Yes" << endl;
            }
        }
    }




}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        solve();

    return 0;
}