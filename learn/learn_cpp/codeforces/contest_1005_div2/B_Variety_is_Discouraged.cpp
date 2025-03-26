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
    vi a(n);
    vector<int> num(n+10, 0);
    rep(i, n){
        int x;cin >> x;
        a[i] = x;
        num[x] += 1;
    }

    pair<int, int> ans = {1, 0};
    int l=0, r=0;
    while (r < n){
        // cout << "l: " << l << " " << r << endl;
        if ((r < n && l < n) && num[a[l]] == 1){
            // cout << "here" << endl;
            while (r+1 < n && num[a[r+1]] == 1){
                r += 1;
            }
            if (r-l > (ans.second - ans.first)){
                ans = {l, r};
            }
            l = r;
        }
        l += 1;
        r += 1;
    }

    if (ans.second - ans.first >= 0){
        cout << ans.first+1 << " " << ans.second+1 << endl;
    }else{
        cout << 0 << endl;
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