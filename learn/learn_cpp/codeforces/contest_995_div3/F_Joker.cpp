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
void logic(int j, int m, int n, set<int> & pos, map< array<int, 3>, bool> & dp, vi & a, set<int> & psizes){
    
    if (j >= n){
        return;
    }
    if (dp[{n, m, j}]){
        return;
    }
    dp[{n, m, j}] = 1;
    if (a[j] < m){
        pos.insert(m-1);
        if (j+1 < n){
            logic(j+1, m, n, pos, dp, a, psizes);
            logic(j+1, m-1, n, pos, dp, a, psizes);
        }
        psizes.insert(pos.size());
    }else if (a[j] > m){
        pos.insert(m+1);
        if (j+1 < n){
            logic(j+1, m, n, pos, dp, a, psizes);
            logic(j+1, m+1, n, pos, dp, a, psizes);
        }
        psizes.insert(pos.size());
    }else{
        logic(j+1, 1, n, pos, dp, a, psizes);
        logic(j+1, n, n, pos, dp, a, psizes);
    }
}


void solve(){

    int n, m, q;cin >> n >> m >> q;
    vi a(q);
    rep(i, q) cin >> a[i];
    set<int> pos;
    pos.insert(m);
    map<array<int, 3>, bool> dp;
    set<int> psizes;
    logic(0, m, n, pos, dp, a, psizes);
    for (auto ele: psizes){
        cout << ele << " ";
    }
    cout << endl; 
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