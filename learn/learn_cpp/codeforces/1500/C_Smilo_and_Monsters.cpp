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
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(all(a));
    int i=0, j=n-1;
    int ans = 0;
    while (i < j){
        int combo = 0;
        while (i < j){
            // cout << combo << endl;
            if (a[i]+combo >= a[j] && i < j){
                a[i] -= a[j]-combo;
                if (a[i] == 0){i += 1;}
                combo = a[j];
                ans += combo + 1;
                combo = 0;
                j -= 1;
                break;
            }else if (a[i]+combo < a[j] && i == j-1){
                ans += (combo + a[i] + a[j] + 1)/2 + 1;

                cout << ans << endl;return;
            }else{
                combo += a[i];
                a[i] = 0;
                i+=1;
            }
        }
        // for (auto ele: a){
        //     cout << ele << " ";
        // }cout << endl;
        // cout << "i: " << i << " j: " << j << " combo: " << ans << endl;
        ans += combo;
    }
    if (i == j){
        if (a[i] == 1){ans += 1;}
        else{
            ans += (a[i]+1)/2 + 1;
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