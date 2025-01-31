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
    map<int, int> diffNum;
    map<int, int> sumNum;
    map<int, int> xNum;
    map<int, int> yNum;

    // diff ->
    rep(i, n){
        int x, y;
        cin >> x >> y;
        xNum[x] += 1;
        yNum[y] += 1;
        diffNum[x-y] += 1;
        sumNum[x+y] += 1;
    }

    int ans = 0;
    for (auto ele: diffNum){
        if (ele.second >= 2){
            ans += ele.second * (ele.second - 1);
        }
    }
    for (auto ele: xNum){
        if (ele.second >= 2){
            ans += ele.second * (ele.second - 1);
        }
    }
    for (auto ele: yNum){
        if (ele.second >= 2){
            ans += ele.second * (ele.second - 1);
        }
    }
    for (auto ele: sumNum){
        if (ele.second >= 2){
            ans += ele.second * (ele.second - 1);
        }
    }
    cout << ans << endl;

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