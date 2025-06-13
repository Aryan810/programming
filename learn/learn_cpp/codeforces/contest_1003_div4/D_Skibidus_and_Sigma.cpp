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
    int ans = 0;
    vector<pair<int, int> > sms(n);
    vector<vector<int> > grid(n, vector<int>(m));
    for (int i=0;i<n;i++){
        int sm = 0;
        // int p = 0;
        for (int j=0;j<m;j++){
            int x;
            cin >> x;
            grid[i][j] = x;
            // p += x*i;
            sm += x;
        }

        sms[i] = {sm, i};
        // ans += sm*n*(m+1) - p;
    }
    sort(rall(sms));
    int k = n*m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            ans += k*grid[sms[i].second][j];
            k -= 1;
        }
    }
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