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
    string s1, s2;
    cin >> s1 >> s2;

    int x = 0;
    int y = 0;
    for (int i=0;i<n;i++){
        if (i&1){
            if (s1[i] == '0'){
                y += 1;
            }
            if (s2[i] == '0'){
                x += 1;
            }
        }else{
            if (s2[i] == '0'){
                y += 1;
            }
            if (s1[i] == '0'){
                x += 1;
            }
        }
    }
    // cout << x << " " << y << endl;
    if (x >= (n+1)/2 && y >= n/2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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