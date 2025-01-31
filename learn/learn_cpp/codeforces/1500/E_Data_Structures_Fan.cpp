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
    vi cum(n+1);
    cum[0] = 0;
    int zor = 0;
    rep(i, n){
        int x;
        cin >> x;
        zor ^= x;
        cum[i+1] = zor;
        a[i] = x;
    }
    string s;
    cin >> s;
    int zeros=0, ones=0;
    rep(i, n){
        if (s[i] == '0'){
            zeros ^= a[i];
        }else{
            ones ^= a[i];
        }
    }

    int q;
    cin >> q;
    rep(i, q){
        int typ;cin >> typ;
        if (typ == 1){  
            int l, r;
            cin >> l >> r;
            ones ^= (cum[r]^cum[l-1]);
            zeros ^= (cum[r]^cum[l-1]);
        }else{
            int g;
            cin >> g;
            if (g){
                cout << ones << " ";
            }else{
                cout << zeros << " ";
            }
        }
    }cout << endl;
    

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