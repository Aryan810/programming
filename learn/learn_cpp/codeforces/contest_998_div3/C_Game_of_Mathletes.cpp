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

    int n, k;
    cin >> n >> k;
    map<int, int> num;
    vi a(n);
    rep(i, n){
        int x;
        cin >> x;
        num[x] += 1;
        a[i] = x;
    }
    int ans = 0;
    for (int i=0;i<n;i++){
        if (num[a[i]] > 0){
            int comp = k - a[i];
            // cout << comp << " " << num[comp] << endl;
            if (comp >= 0 && num[comp] > 0){
                if (2*a[i] != k){
                    ans += min(num[a[i]], num[comp]);
                    num[a[i]] = 0;
                    num[comp] = 0;
                }else{
                    ans += num[a[i]]/2;
                    num[a[i]] = 0;
                }
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