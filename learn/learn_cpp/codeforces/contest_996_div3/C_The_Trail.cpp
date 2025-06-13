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

    int n, m;
    cin >> n >> m;
    string s;cin >> s;
    vector<vector<int> > grid(n, vector<int>(m));
    rep(i, n){
        rep(j, m){
            cin >> grid[i][j];
        }
    }
    int M = 0;
    if (s[0] == 'D'){
        grid[0][0] = M - accumulate(all(grid[0]), 0ll);
    }else{
        int sm = 0;
        for (int i=0;i<n;i++){
            sm += grid[i][0];
        }
        grid[0][0] = M - sm;
    }
    int x=0, y=0;
    vi row(n, 0);
    vi col(m, 0);
    for (int i=0;i<s.size();i++){
        if (s[i] == 'D'){
            x += 1;
        }else{
            y += 1;
        }
        row[x] += 1;
        col[y] += 1;
    }
    x = 0;y = 0;
    for (int i=0;i<s.size();i++){
        pair<int, int> prev = {x, y};
        if (s[i] == 'D'){
            x += 1;
        }else{
            y += 1;
        }
        if (col[y] == 1){
            int sm = 0;
            for (int i=0;i<n;i++){
                sm += grid[i][y];
            }
            grid[x][y] = M - sm;
            row[x] -= 1;
            col[y] -= 1;
        }else if (row[x] == 1){
            grid[x][y] = M - accumulate(all(grid[x]), 0ll);
            row[x] -= 1;
            col[y] -= 1;
        }
        
    }
    for (auto row: grid){
        for (auto cell: row){
            cout << cell << " ";
        }cout << endl;
    }

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