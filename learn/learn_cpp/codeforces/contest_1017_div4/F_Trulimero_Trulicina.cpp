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
    int k;cin >> k;

    if (n%k == 0 && m%k == 0){
        int curr = 0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cout << curr+1 << " ";
                curr = (curr + 1)%k;
            }curr = (curr + 1)%k;
            cout << endl;
        }
    }else if (n%k != 0){
        vector<vector<int> > grid(n, vector<int>(m));
        int curr = 0;   
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                grid[j][i] = curr + 1;
                curr = (curr + 1)%k;
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cout << grid[i][j] << " ";
            }cout << endl;
        }
    }else{
        int curr = 0;   
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cout << curr + 1 << " ";
                curr = (curr + 1)%k;
            }cout << endl;
        }
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