// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define each(x, a) for (auto &x : a)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pi pair<int, int>
#define p(a, b) pair<a, b>
#define vi vector<int>
#define vii vector<int>::iterator
#define vvi vector<vector<int> >
#define vv(x) vector<vector<x> >
#define PRECISION(x) cout << fixed << setprecision(x);
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define umap(x, y) unordered_map<x, y, custom_hash>
const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}
void solve(){
    
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    
    // case - 1
    if (c < max(a, b) && c > max(a, b)+1){
        cout << -1 << endl;return;
    }

    int temp = k;
    int mna = binexpiter(10, a-1);
    int mxa = binexpiter(10, a)-1;
    int mnc = binexpiter(10, c-1);
    int mnb1 = binexpiter(10, b-1);
    int mxb1 = binexpiter(10, b)-1;
    int mxc = 10*mnc - 1;
    int i;
    for (i=mna;i<=mxa;i++){
        int mnb = max(mnc-i, mnb1);
        int mxb = min(mxc-i, mxb1);
        if (temp - max(0ll, mxb-mnb+1) <= 0){
            break;
        }else{
            temp -= max(0ll, mxb-mnb+1);
        }
    }
    if (i > mxa){
        cout << -1 << endl;return;
    }
    int j;
    for (j=mnb1;j<=mxb1;j++){
        if (j+i <= mxc && j+i >= mnc){
            temp -= 1;
            if (temp == 0){
                cout << i << " + " << j << " = " << i+j << endl;return;
            }
        }
    }
    cout << -1 << endl;return;
   
    // int mnc = binexpiter(10, c-1);
    // // case - 2
    // if (c == max(a, b)+1){
    //     if (a == b){
    //         int temp = k;
    //         int i;
    //         int mxb = binexpiter(10, b)-1;
    //         int mna = max(binexpiter(10, a-1), mnc - mxb);
    //         int mnb1 = binexpiter(10, b-1);
    //         int mxa = 10*mna - 1;
    //         int mnb;
    //         for (i=mna;i<=(mxa);i++){
    //             mnb = max(mnc - i, mnb1);
    //             if (temp <= (mxb-mnb+1)){
    //                 break;
    //             }else{
    //                 temp -= (mxb - mnb + 1);
    //             }
    //         }
    //         if (i > mxa){
    //             cout << -1 << endl;return;
    //         }

    //         cout << i << " + " << (mnb + temp - 1) << " = " << (i + mnb + temp - 1) << endl;
    //     }else if (a < b){
    //         int temp = k;
    //         int i;
    //         int mxb = binexpiter(10, b)-1;
    //         int mnb1 = binexpiter(10, b-1);
    //         int mna = binexpiter(10, a-1);
    //         int mxa = 10*mna - 1;
    //         int mnb;
    //         for (i=mna;i<=(mxa);i++){
    //             mnb = max(mnc - i, mnb1);
    //             if (temp <= (mxb-mnb+1)){
    //                 break;
    //             }else{
    //                 temp -= (mxb - mnb + 1);
    //             }
    //         }
    //         if (i > mxa){
    //             cout << -1 << endl;return;
    //         }

    //         cout << i << " + " << (mnb + temp - 1) << " = " << (i + mnb + temp - 1) << endl;
    //     }else{
    //         int temp = k;
    //         int i;
    //         int mnb1 = binexpiter(10, b-1);
    //         int mxb = binexpiter(10, b) - 1;
    //         int mna = max(binexpiter(10, a-1), mnc - mxb);
    //         int mxa = binexpiter(10, a) - 1;
    //         int mnb;
    //         for (i=mna;i<=(mxa);i++){
    //             mnb = max(mnc - i, mnb1);
    //             if (temp <= (mxb-mnb+1)){
    //                 break;
    //             }else{
    //                 temp -= (mxb - mnb + 1);
    //             }
    //         }
    //         if (i > mxa){
    //             cout << -1 << endl;return;
    //         }
    //         cout << i << " + " << (mnb + temp - 1) << " = " << (i + mnb + temp - 1) << endl;
    //     }
    //     return;
    // }

    // // case - 3
    // int mxc = 10 * mnc - 1;
    // if (a < b){
    //     int temp = k;
    //     int i;
    //     int mna = binexpiter(10, a-1);
    //     int mxa = 10*mna - 1;
    //     int mnb = binexpiter(10, b-1);
    //     for (i=mna;i<=(mxa);i++){
    //         int mxb = min(10*mnb-1, mxc - i);
    //         if (temp <= (mxb-mnb + 1)){
    //             break;
    //         }else{
    //             temp -= (mxb - mnb + 1);
    //         }
    //     }
    //     if (i > mxa){
    //         cout << -1 << endl;return;
    //     }
    //     // mnb = mnc - i;
    //     cout << i << " + " << (mnb + temp - 1) << " = " << (i + mnb + temp - 1) << endl;
    // }else if (a == b){
    //     int temp = k;
    //     int i;
    //     int mnb = binexpiter(10, b-1);
    //     int mna = binexpiter(10, a-1);
    //     int mxa = min(10*mna-1, mxc - mnb);
    //     for (i=mna;i<=(mxa);i++){
    //         int mxb = min(10*mnb-1, mxc - i);
    //         if (temp <= (mxb-mnb+1)){
    //             break;
    //         }else{
    //             temp -= (mxb - mnb + 1);
    //         }
    //     }
    //     if (i > mxa){
    //         cout << -1 << endl;return;
    //     }
    //     cout << i << " + " << (mnb + temp - 1) << " = " << (i + mnb + temp - 1) << endl;
    // }else{
    //     int temp = k;
    //     int i;
    //     int mna = max(binexpiter(10, a-1),  mnc - (binexpiter(10, b) - 1));
    //     int mxb1 = binexpiter(10, b) - 1;
    //     int mnb1 = binexpiter(10, b-1);
    //     int mxa = mxc - binexpiter(10, b-1);
    //     int mxb, mnb;
    //     for (i=mna;i<=(mxa);i++){
    //         mxb = min(mxc - i, mxb1);
    //         mnb = max(mnb1, mnc - i);
    //         // cout << i << " " << mxb << " " << mnb << " " << temp << endl;
    //         if (temp <= (mxb-mnb+1)){
    //             break;
    //         }else{
    //             temp -= (mxb - mnb + 1);
    //         }
    //     }
    //     if (i > mxa){
    //         cout << -1 << endl;return;
    //     }
    //     // cout << i << " " << mnb << " " << temp << endl;
    //     cout << i << " + " << (mnb + temp - 1) << " = " << (i + mnb + temp - 1) << endl;
    // }

}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}