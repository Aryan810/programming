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

    int n, x, y;
    cin >> n >> x >> y;
    vector<int> diff;
    string a, b;
    cin >> a >> b;
    rep(i, n){
        if (a[i] != b[i]){
            diff.push_back(i);
        }
    }
    if (diff.size()&1){
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    if (diff.size() > 2){
        ans += y*(diff.size())/2;
    }else if (diff.size() == 2){
        if (diff[1]-diff[0] == 1){
            if (x > 2*y){
                int af = a.size()-diff[1]-1;
                int bef = a.size()-af-2;
                if (af == 1 && bef == 1){
                    if (x > 3*y){
                        ans += 3*y;
                    }else{
                        ans += x;
                    }
                }else if (af < 2 && bef < 2){
                    ans += x;
                }else{
                    ans += 2*y;
                }
            }else{
                ans += x;
            }
        }else{
            ans += y;
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