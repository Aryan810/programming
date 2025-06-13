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
    vector<int> rows(3);
    vector<int> cols(3);
    cin >> rows[0] >> cols[0];
    cin >> rows[1] >> cols[1];
    cin >> rows[2] >> cols[2];
    int row, col;
    int rl, cl;
    if (count(all(rows), rows[0]) == 1){
        row = rows[1];
        rl = rows[0];
    }else{
        row = rows[0];
        if (rows[1] == row){
            rl = rows[2];
        }else{
            rl = rows[1];
        }
    }
    if (count(all(cols), cols[0]) == 1){
        col = cols[1];
        cl = cols[0];
    }else{
        col = cols[0];
        if (cols[1] == col){
            cl = cols[2];
        }else{
            cl = cols[1];
        }
    }
    // array<int, 2> cmn = {row, col};
    // array<int, 2> f = {row, cl};
    // array<int, 2> s = {rl, col};
    int a, b;
    cin >> a >> b;
    if ((row <= rl && col <= cl)){
        // cout << "HERE1" << endl;
        if (row == 1 && col == 1){
            if (a == row || b == col){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            if (llabs(row - a)%2 == 0 || llabs(col - b)%2 == 0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
        return;
    }

    if ((row > rl && col > cl)){
        // cout << "HERE2" << endl;
        // cout << row << " " << col << endl;
        if (row == n && col == n){
            if (a == row || b == col){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            if(llabs(row - a)%2 == 0 || llabs(col - b)%2 == 0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
        return;

    }

    if ((row > rl && col < cl)){
        // cout << "HERE3" << endl;

        if (row == n && col == 1){
            if (a == row || b == col){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            if(llabs(row - a)%2 == 0 || llabs(col - b)%2 == 0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
        return;

    }

    if ((row < rl && col > cl)){
        // cout << "HERE4" << endl;

        if (row == 1 && col == n){
            if (a == row || b == col){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            if (llabs(row - a)%2 == 0 || llabs(col - b)%2 == 0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
        return;

    }
  
    // if ((row + a)%2 == 0 && (col + b)%2 == 0){
    //     cout << "YES" << endl;
    // }else{
    //     if (abs(rl - a)%2 == 0 && abs(cl - b)%2 == 0){
    //         cout << "YES" << endl;
    //     }else{
    //         cout << "NO" << endl;
    //     }
    // }
    // cout << row << " " << rl << " " << col << " " << cl << endl;
 
    
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