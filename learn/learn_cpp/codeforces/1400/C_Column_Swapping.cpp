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
    vector<vector<int> > grid(n, vector<int>(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    // cout << "here" << endl;
    // iterating rows
    for (int i=0;i<n;i++){
        //checking no. of bads;
        vector<int> & temp = grid[i];
        if (!is_sorted(all(temp))){
            vector<int> cum(m);
            int p = 1e18;
            for (int j=m-1;j>=0;j--){
                p = min(temp[j], p);
                cum[j] = p;
            }
            int a = -1;
    
            for (int j=0;j<m;j++){
                if (cum[j] != temp[j]){
                    a = j;
                    break;
                }
            }
            // cout << "a: " << a << endl;
            for (int j=m-1;j>a;j--){
                if (temp[j] < temp[a]){
                    swap(temp[j], temp[a]);
                    if (is_sorted(all(temp))){
                        for (int k=0;k<n;k++){
                            if (k != i){
                                swap(grid[k][a], grid[k][j]);
                                if (!is_sorted(all(grid[k]))){
                                    cout << -1 << endl;
                                    return;
                                }
                            }
                        }
                        cout << a+1 << " " << j+1 << endl;
                        return;
                    }else{
                        cout << -1 << endl;
                        return;
                    }
                }
            }
            cout << -1 << endl;return;
        }
    }
    cout << 1 << " " << 1 << endl;
    
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