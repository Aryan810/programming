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

    bool log = 0;
    int ans = 0;
    
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        if (s == "login"){
            log = 1;
        }else if (s == "logout"){
            log = 0;
        }else if (s == "private"){
            if (log == 0){
                ans += 1;
            }
        }
    }
    cout << ans << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;

    while(test--){
        solve();
    }

    return 0;
}