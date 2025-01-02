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

    int n, t;
    cin >> n >> t;

    vi a(n);
    rep(i, n) cin >> a[i];

    vi cum(n+1);
    cum[0] = 0;
    int sum = 0;
    for (int i=0;i<n;i++){
        sum += a[i];
        cum[i+1] = sum;
    }
    int ans = 0;
    for (int i=0;i<n;i++){
        auto it = --upper_bound(cum.begin()+i+1, cum.end(), t+(cum[i]));
        int book = 0;
        if (it < cum.begin()+i+1){
            book = 0;
            // cout << "here: " << endl;
        }else{
            book = ((it-cum.begin()) - i);
        }
        // cout << "book: " << book << endl;
        ans = max(book, ans);
    }
    cout << ans << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        solve();


    return 0;
}