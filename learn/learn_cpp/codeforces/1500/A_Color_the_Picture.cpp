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

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    rep(i, k) cin >> a[i];
    sort(rall(a));
    auto b = a;
    int two = 0;
    int three = 0;
    // for n
    int tot = 0;
    // if (m&1){
    //     if (b[0] >= 3*n){
    //         three += 1;
    //         b[0] -= 3*n;
    //     }
    // }
    for (int i=0;i<b.size();i++){
        if (b[i] >= 2*n){
            two += b[i]/(2*n);
            three += b[i]/(3*n);
            tot += b[i]/n;
        }
    }
    // cout << two << " " << three << endl;
    if (tot >= m){
        if (m&1){
            if (three > 0){
                cout << "Yes" << endl;
                return;
            }
        }else{
            cout << "Yes" << endl;
            return;
        }
    }
    two = 0;
    three = 0;
    tot = 0;
    b[0]=a[0];
    // for m
    for (int i=0;i<b.size();i++){
        if (b[i] >= 2*m){
            two += b[i]/(2*m);
            three += b[i]/(3*m);
            tot += b[i]/m;
        }
    }
    // cout << two << " " << three << endl;
    if (tot >= n){
        if (n&1){
            if (three > 0){
                cout << "Yes" << endl;
                return;
            }
        }else{
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;

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