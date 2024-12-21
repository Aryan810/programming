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
            cout << i%3 << " ";
        }
        int x = (n-2)%3;
        if (x == 1){
            cout << 2 << " ";
        }else if (x == 2){
            cout << 1 << " ";
        }else if (x == 0){
            cout << 1 << " ";
        }cout << endl;
        return;
    }
    vi ans(n);
    for (int i=0;i<y-x;i++){
        ans[i+x-1] = i%3;
    }
    int fory = (y-x)%2;
    bool tochange = 0;
    if ((y-x-1)%3 == 2){
        fory = 1;
        tochange = 1;
    }
    ans[y-1] = fory;
    
    if (y == n){
        for (int i=1;i<=(x-1);i++){
            ans[x-i-1] = i%3;
        }
        set<int> s = {0, 1, 2};
        s.erase(ans[n-1]);
        s.erase(ans[n-2]);
        ans[0] = *s.begin();
    }else{
        for (int i=1;i<=(n-y + x-2);i++){
            ans[(x-i-1 >= 0)?(x-i-1):(n-abs(x-i-1))] = i%3;
        }
        set<int> s = {0, 1, 2};
        s.erase(ans[y-2]);
        s.erase(ans[y-1]);
        ans[y] = *s.begin();
    }
    if (tochange){
        ans[y-2] = 0;
    }
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