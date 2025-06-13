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
    vector<string> met(n);
    rep(i, n){
        cin >> met[i];
    }

    vector<string> ans(n);
    for (int i=0;i<n;i++){
        int l=0, r=0, u=0, d = 0;
        for (int j=0;j<m;j++){
            switch (met[i][j])
            {
            case 'U':
                u++;
                break;
            case 'D':
                d++;
                break;
            case 'L':
                l ++;
                break;
            case 'R':
                r++;
                break;
            default:
                break;
            }
            ans[i].push_back('.');
        }
        if (l!=r || (((u+d)&1) || ((l+r+u+d)&1))){
            cout << -1 << endl;
            return;
        }
    }

    for (int j=0;j<m;j++){
        int l=0, r=0, u=0, d = 0;
        for (int i=0;i<n;i++){
            switch (met[i][j])
            {
            case 'U':
                u++;
                break;
            case 'D':
                d++;
                break;
            case 'L':
                l ++;
                break;
            case 'R':
                r++;
                break;
            default:
                break;
            }
        }
        if (u!=d || (((l+r)&1) || ((l+r+u+d)&1))){
            cout << -1 << endl;
            return;
        }
    }
    // cout << "printing!" << endl;
    // for (auto ele: met){
    //     cout << ele << endl;
    // }

    for (int i=0;i<m;i++){
        bool forl = 1, forr = 0;
        for (int j=0;j<n;j++){
            if (ans[j][i] == '.' && met[j][i] == 'L'){
                if (forl){
                    ans[j][i] = 'B';
                    ans[j][i+1] = 'W';
                    forl = 0;
                }else{
                    ans[j][i] = 'W';
                    ans[j][i+1] = 'B';
                    forl = 1;
                }
            }else if (ans[j][i] == '.' && met[j][i] == 'R'){
                if (forr){
                    ans[j][i] = 'B';
                    ans[j][i-1] = 'W';
                    forr = 0;
                }else{
                    ans[j][i] = 'W';
                    ans[j][i-1] = 'B';
                    forr = 1;
                }
            }
        }
    }

    for (int i=0;i<n;i++){
        bool foru = 1, ford = 0;
        for (int j=0;j<m;j++){
            if (ans[i][j] == '.' && met[i][j] == 'U'){
                if (foru){
                    ans[i][j] = 'B';
                    ans[i+1][j] = 'W';
                    foru = 0;
                }else{
                    ans[i][j] = 'W';
                    ans[i+1][j] = 'B';
                    foru = 1;
                }
            }else if (ans[i][j] == '.' && met[i][j] == 'D'){
                if (ford){
                    ans[i][j] = 'B';
                    ans[i-1][j] = 'W';
                    ford = 0;
                }else{
                    ans[i][j] = 'W';
                    ans[i-1][j] = 'B';
                    ford = 1;
                }
            }
        }
    }
    for (auto s: ans){
        cout << s << endl;
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