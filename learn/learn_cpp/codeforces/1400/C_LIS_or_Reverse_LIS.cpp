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
    map<int, int> m;
    int sames = 0;
    int diff = 0;
    rep(i, n){
        int x;
        cin >> x;
        m[x] += 1;
    }
    for (auto ele: m){
        if (ele.second > 1){
            sames += 1;
        }else{
            diff += 1;
        }
    }
    int a=sames, b=sames;
    if (diff > 0){
        a += 1;
        b += 1;
        diff -= 1;
    }
    if (diff&1){
        a += diff/2;
        b += diff/2 + 1;
    }else{
        a += diff/2;
        b += diff/2;
    }
    cout << min(a, b) << endl;

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