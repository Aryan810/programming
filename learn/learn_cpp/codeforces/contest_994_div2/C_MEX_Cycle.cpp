#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){
    int n, x, y;cin >> n >> x >> y;
    if (x == 1 && y == n){
        for (int i=0;i<n-1;i++){
            cout << i%2 << " ";
        }
        int x = (n-2)%2;
        if (x == 1){
            cout << 2 << " ";
        }else if (x == 0){
            cout << 1 << " ";
        }cout << endl;
        return;
    }
    vi ans(n);
    ans[x-1] = 0;
    for (int i=1;i<=(y-x-1);i++){
        ans[x+i-1] = i%2;
    }
    for (int i=1;i<=(n-y + x-1);i++){
        ans[(x-i-1 >= 0)?(x-i-1):(n-abs(x-i-1))] = i%2;
    }
    set<int> s = {0, 1, 2, 3};
    s.erase(ans[x-1]);
    s.erase(ans[y%n]);
    s.erase(ans[(y-2)]);
    ans[y-1] = *s.begin();
    for (auto ele: ans){
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