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

    int n;cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int ans = 0;
    while (a.size() > 1){
        int m = a.size();
        // for (auto ele: a){
        //     cout << ele << " ";
        // }cout << endl;
        if (a[m-1] >= a[m-2]){
            a.pop_back();
        }else{
            if (a[m-2] > 2*a[m-1]){
                int x = a.back();
                a.pop_back();
                if (a.back()%x == 0){
                    ans += a.back()/x - 1;
                    a.back() = x;
                }else{
                    int k = a.back()/x + (a.back()%x != 0);
                    ans += k-1;
                    a.back() = a.back()/k;
                }
            }else{
                a.pop_back();
                a.back() = a.back()/2;
                ans += 1;
            }
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