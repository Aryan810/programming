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
vector<vector<int> > dp;
int logic(int i, int j, string & c, string & a, string & b){

    if (i == a.size() && j == b.size()){
        return 0;
    }

    if (dp[i][j] != -1){
        return dp[i][j];
    }

    int pos = i + j;
    int res = 1e18;
    
    if (i < a.size()){
        res = min(res, (logic(i+1, j, c, a, b) + (a[i] != c[pos])));
    }
    if (j < b.size()){
        res = min(res, (logic(i, j+1, c, a, b) + (b[j] != c[pos])));
    }
    return dp[i][j] = res;


    // if (i < a.size() && (dp[i+1][j] == -1)){
    //     int temp = -1;
    //     if (c[i+j] == a[i]){
    //         temp = dp[i][j];
    //     }else{
    //         temp = dp[i][j] + 1;
    //     }
    //     if (dp[i+1][j] != -1){
    //         dp[i+1][j] = min(temp, dp[i+1][j]);
    //     }else{
    //         dp[i+1][j] = temp;
    //     }
    //     logic(i+1, j, c, a, b, dp);

    // }  
    // if (j < b.size() && (dp[i][j+1]== -1)){
    //     int temp = -1;
    //     if (c[i+j] == b[j]){
    //         temp = dp[i][j];
    //     }else{
    //         temp = dp[i][j] + 1;
    //     }
    //     if (dp[i][j+1] != -1){
    //         dp[i][j+1] = min(temp, dp[i][j+1]);

    //     }else{
    //         dp[i][j+1] = temp;
    //     }
    //         logic(i, j+1, c, a, b, dp);
    // }
     
}

void solve(){
    string a, b, c;
    cin >> a >> b >> c;
    dp.assign(a.size()+1, vector<int>(b.size()+1, -1));
    cout << logic(0, 0, c, a, b) << endl;
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