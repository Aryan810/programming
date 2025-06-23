#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace __gnu_pbds;
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<int>::iterator
#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){

    int n, q;
    cin >> n >> q;
    vi a(n);
    rep(i, n) cin >> a[i];

    vector<int> cum(n+1);
    cum[0] = 0;
    int sm = 0;
    bool cons = 0;
    vector<int> v(n, 0);
    for (int i=1;i<(n);i++){
        if (a[i] <= a[i-1]){
          
            if (cons){sm -= 1;v[i] = -1;}else{
                v[i] = -2;
                cons = 1;
            }
        }else{
            cons = 0;
        }
        cum[i+1] = sm;
    }

    for (int i=0;i<q;i++){
        int l, r;
        cin >> l >> r;
        if (l == r){
            cout << 1 << endl;
        }else{
            int raw = r-l+1 + cum[r] - cum[l];
            if (v[l] == -1){
                raw += 1;
            }
            cout << raw << endl;
        }
    }




}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

        solve();


    return 0;
}