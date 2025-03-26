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

    if (n&1){
        int curr = n-1;
        int x = (n-1)/2;
        while (curr > 0){
            for (int i=0;i<min(x, curr);i++){
                cout << 1 << " ";
            }
            for (int i=0;i<(curr-x);i++){
                cout << -1 << " ";
            }
            curr -= 1;
        }cout << endl;
    }else{
        int curr = n-1;
        int x = (n-1)/2;
        while (curr > 0){
            for (int i=0;i<min(x, curr);i++){
                cout << 1 << " ";
            }
            if (curr > x){cout << 0 << " ";}
            for (int i=0;i<(curr-x-1);i++){
                cout << -1 << " ";
            }
            curr -= 1;
        }cout << endl;
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