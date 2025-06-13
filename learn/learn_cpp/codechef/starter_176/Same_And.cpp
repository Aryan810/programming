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

    int x = 1;
    vector<int> bits;
    bits.push_back(0);
    for (int i=0;i<63;i++){
        if (!(n&x)){
            bits.push_back(x);
        }
        x = x << 1;
    }

    vector<int> out;
    for (int i=0;i<bits.size();i++){
        if (n+bits[i] <= m){
            out.push_back(n+bits[i]);
        }
    }
    if (out.size() == 1){cout << -1 << endl;return;}
    cout << out.size() << endl;
    for (auto ele: out){
        cout << ele << " ";
    }cout << endl;

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