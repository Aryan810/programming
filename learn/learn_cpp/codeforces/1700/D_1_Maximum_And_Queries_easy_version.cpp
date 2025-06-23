// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>
const int M = 1e9 + 7;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

bool check(int mid, int & n, vi & a, int k){
    for (int j=0;j<=32;j++){
            if ((1ll << j)&mid){
                cout << 1;
            }else{
                cout << 0;
            }
        }cout << endl;cout << endl;
    int oper = 0;
    for (int i=0;i<n;i++){
        int mo = 0;
        int st = 0;
        int temp = 1;
        int mxMid = log2(mid);
        cout << mxMid << endl;
        for (int j=0;j<32;j++){
            if ((1ll << j)&a[i]){
                cout << 1;
            }else{
                cout << 0;
            }
        }cout << endl;
        // int ex = 0;
        for (int j=0;j<=mxMid;j++){
            // cout << a[i] << endl;
            bool x = ((int)(a[i]&temp) != 0ll);
            bool y = ((int)(mid&temp) != 0ll);
            // cout << mid << " " << (mid&temp) << " " << temp << " " << a[i] << endl;
            // cout << x << " - - " << y << endl;
            if (x && !y){
                st += temp;
                // ex += temp;
            }else if (!x && y){
                mo += temp-st;
                st = 0;
                // ex = 0;
            }
            temp = temp << 1;
            // if (temp > mid){
            //     break;
            // }
        }
        cout << a[i] << " -> " << mo << " " << st << " " <<  endl;
        // for (int j=0;j<32;j++){
        //     if ((1ll << j)&a[i]){
        //         cout << 1;
        //     }else{
        //         cout << 0;
        //     }
        // }cout << endl;
        oper += max(0ll, mo);
        if (oper > k){
            return 0;
        }
    }
    cout << mid << " " << oper << " " << k << endl;
    return oper <= k;
}

void solve(){
    
    int n, q;
    cin >> n >> q;

    vi a(n);
    rep(i, n) cin >> a[i];

    for (int i=0;i<q;i++){
        int k;
        cin >> k;
        vi b = a;
        int mxbit = log2((1e18)/(n));

        for (int j=mxbit;j>=0;j--){
            int mn = 0;
            for (int l=0;l<n;l++){
                if (!((1ll << j)&b[l])){
                    // cout << "HEr" << endl;
                    mn += (1ll << j) - (b[l]%(1ll << j));
                }
            }
            // cout << j << " " << mn << endl;
            if (mn <= k){
                k -= mn;
                for (int l=0;l<n;l++){
                    if (!((1ll << j)&b[l])){
                        b[l] += (1ll << j) - (b[l]%(1ll << j));
                    }
                }
            }
        }
        int ans = b[0];
        for (int i=0;i<n;i++){
            ans = ans & b[i];
        }
        // if (ans > (int)(1e18 + 1e6 + 100)){
        //     cout << 0 << endl;
        // }else{
            cout << ans << endl;
        // }
        
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    // int test;
    // cin >> test;

    // while(test--){
        solve();
    // }

    return 0;
}