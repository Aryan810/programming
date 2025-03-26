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
    vector<string> grid(n);
    int x=0, y=0;
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        int sm = 0;
        for (auto ele: s){
            sm += ele-'0';
        }
        if (sm&1){
            x += 1;
        }
        grid[i] = s;
    }

    for (int i=0;i<m;i++){
        int sm = 0;

        for (int j=0;j<n;j++){
            sm += grid[j][i] - '0';
        }
        if (sm&1){
            y += 1;
        }
    }
    cout << max(x, y) << endl;
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