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

    int n;
    cin >> n;
    vector<vector<int> > grid(n, vector<int>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }

    vector<int> num(n, 0);
    
    for (int i=0;i<n;i++){
        int sm = 0;
        for (int j=0;j<n;j++){
            if (sm == j){
                num[j] += 1;
            }
            sm += grid[i][n-1-j];
        }
    }
    int ans = n-1;
    while (ans >= 0){
        bool pos = 1;
        for (int i=ans;i>=0;i--){
            if (num[i] < ans - i + 1){
                pos = 0;
                break;
            }
        }
        if (pos){
            break;
        }
        ans -= 1;
    }
    cout << ans+1 << endl;

    

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