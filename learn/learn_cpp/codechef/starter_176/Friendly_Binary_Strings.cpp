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
    string a, b;
    cin >> a >> b;

    int p=0, q=0, r=0; // p -> one-one, q -> zero-zero, r->one-zero;
    for (int i=0;i<n;i++){
        if (a[i] == b[i]){
            if (a[i] == '1'){
                p += 1;
            }else{
                q += 1;
            }
        }else{
            r += 1;
        }
    }
    // cout << p << " " << q << " " << r << endl;
    int odds = (p%2 != 0) + (q%2 != 0) + (r%2 != 0);

    if (n&1){
        if (odds == 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }else{
        if (odds == 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }


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