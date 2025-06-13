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

bool check(int l, int r, vector<vector<int> > & cum, int k){
    int value = 0;
    int x = 1;
    for (int i=0;i<32;i++){
        if ((cum[r+1][i] - cum[l][i]) == 0){
            value += x;
        }
        x = x << 1;
    }
    // cout << value << " : " << k << endl;
    return (value >= k);
}

void solve(){

    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    vector<vector<int> > cum(n+1, vector<int>(32, 0));
    for (int i=0;i<n;i++){
        auto prev = cum[i];
        int x = 1;
        for (int j=0;j<32;j++){
            // cout << x << " : " << a[i] << " : " << (a[i]&x) << endl;
            if ((int)(a[i]&x) == 0){prev[j] += 1;}
            x = x << 1;
        }
        cum[i+1] = prev;
    }
    // cout << "CUM -> " << endl;
    // for (auto ele: cum){
    //     for (auto x: ele){
    //         cout << x << " ";
    //     }cout << endl;
    // }
    int q;
    cin >> q;
    while (q--){
        int l,k;cin >> l >> k;
        int low = l-1;
        int high = n-1;
        while (high - low > 1){
            int mid = (high + low)/2;
            if (check(l-1, mid, cum, k)){
                low = mid;
            }else{
                high = mid-1;
            }
        }
        // cout << low << " : " << high << endl;
        if (check(l-1, high, cum, k)){
            cout << high+1 << " ";
        }else if (check(l-1, low, cum, k)){
            cout << low+1 << " ";
        }else{
            cout << -1 << " ";
        }
    }
    cout << endl;

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