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

    int n, s;
    cin >> n >> s;
    if (s < 2*n){
        cout << "NO" << endl;return;
    }else{
        if (s&1){
            cout << "YES" << endl;
            for (int i=0;i<n-1;i++){
                cout << 2 << " ";
            }
            cout << s-2*(n-1) << endl;
            cout << s-2*(n-1) - 2 << endl;
        }else{
            cout << "YES" << endl;
            for (int i=0;i<n-1;i++){
                cout << 2 << " ";
            }cout << s-2*(n-1) << endl;
            cout << 1 << endl;
        }
    }
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve();

    return 0;
}