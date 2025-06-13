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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){

    int n;cin >> n;
    vector<vector<int> > grid(n, vector<int>(n, 0));
    for (int i=0;i<n;i++){
        cin >> grid[i][i];
    }
    for (int i=0;i<n;i++){
        int x = i, y = i;
        int left = grid[x][y]-1;
        while (left != 0){
            pair<int, int> p1 = {x+1, y};
            pair<int, int> p2 = {x, y-1};
            if ((p2.first < n && p2.second >= 0) && grid[p2.first][p2.second] == 0){
                grid[p2.first][p2.second] = grid[i][i];
                x = p2.first;
                y = p2.second;
            }else{
                grid[p1.first][p1.second] = grid[i][i];
                x = p1.first;
                y = p1.second;
            }
            left -= 1;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<(i+1);j++){
            cout << grid[i][j] << " ";
        }cout << endl;
    }
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        solve();

    return 0;
}