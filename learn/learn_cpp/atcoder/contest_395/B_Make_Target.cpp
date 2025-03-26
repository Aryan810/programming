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

    vector<vector<int> > grid(n, vector<int>(n, -1));

    for (int i=1;i<=n;i++){
        int j = n+1-i;
        if (i <= j){
            // cout << "HERE" << " " << i << " " << j << endl;
            for (int k = i;k<=j;k++){
                for (int l = i;l<=j;l++){
                    grid[k-1][l-1] = (i&1)?(1):(0);
                }
            }
        }
    }

    for (auto ele: grid){
        for (auto ele1: ele){
            cout << ((ele1)?'#':'.');
        }cout << endl;
    }


}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   solve();
    return 0;
}