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

void change(vector<vector<int> > & grid, array<int, 6> & c){
    grid[c[0]-1][c[1]-1] ^= 1;
    grid[c[2]-1][c[3]-1] ^= 1;
    grid[c[4]-1][c[5]-1] ^= 1;
}

void solve(){

    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            char x;
            cin >> x;
            a[i][j] = x-'0';
        }
    }
    int k = 0;
    vector<array<int, 6> > out;
    for (int i=0;i<n-1;i++){
        for (int j=0;j<(m-1);j++){
            // case 1
            if (a[i][j] && a[i+1][j]){
                out.push_back({i+1, j+1, i+2, j+1, i+1, j+2});
                change(a, out.back());
                k += 1;
            }else if (a[i][j]){ // case 2
                out.push_back({i+1, j+1, i+1, j+2, i+2, j+2});
                change(a, out.back());

                k += 1;

            }else if (a[i+1][j]){ // case 3
                out.push_back({i+2, j+1, i+2, j+2, i+1, j+2});
                change(a, out.back());

                k += 1;

            }
        }
        // case 1
        if (a[i][m-1] && a[i+1][m-1]){
            out.push_back({i+1, m-1, i+2, m-1, i+1, m});
            change(a, out.back());

            out.push_back({i+1, m-1, i+2, m-1, i+2, m});
            change(a, out.back());


            k += 2;

        }else if (a[i][m-1]){ // case 2
            out.push_back({i+1, m-1, i+2, m-1, i+1, m});
            change(a, out.back());

            out.push_back({i+1, m-1, i+1, m, i+2, m});
            change(a, out.back());

            out.push_back({i+2, m-1, i+2, m, i+1, m});
            change(a, out.back());


            k += 3;

        }else if (a[i+1][m-1]){ // case 3   
            out.push_back({i+1, m-1, i+2, m-1, i+2, m});
            change(a, out.back());

            out.push_back({i+1, m, i+2, m, i+1, m-1});
            change(a, out.back());

            out.push_back({i+1, m, i+2, m, i+2, m-1});
            change(a, out.back());

            k += 3;
        }
    }
    cout << k << endl;
    for (auto ele: out){
        cout << ele[0] << " " << ele[1] << " " << ele[2] << " " << ele[3] << " " << ele[4] << " " << ele[5] << endl;
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