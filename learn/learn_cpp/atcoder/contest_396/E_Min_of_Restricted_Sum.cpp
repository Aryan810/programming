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

    int n, m;cin >> n >> m;
    vi x(m), y(m), z(m), a(n+1, -1);
    rep(i, m){
        cin >> x[i] >> y[i] >> z[i];
    }

    for (int i=0;i<m;i++){
        int ex=x[i], ey=y[i], ez=z[i];
        if (a[ex] != -1 && a[ey] != -1){
            // cout << i << " " << " <1>" << endl;
            if ((int)(a[ex]^a[ey]) != (int)ez){
                // cout << i << " " << a[ey] << " " << a[ex] << " " << ez << endl;
                // for (auto ele: a){
                //     cout << ele << " ";
                // }cout << endl;
                cout << -1 << endl;return;
            }
        }else if (a[ex] == -1 && a[ey] != -1){
            // cout << i << " " << " <2>" << endl;
            a[ex] = (int)(ez^a[ey]);
        }else if (a[ex] != -1 && a[ey] == -1){
            // cout << i << " " << " <3>" << endl;

            a[ey] = (int)(ez^a[ex]);
        }else{
            // cout << i << " " << " <4>" << endl;

            // let one variable '0' (as we want min sum)
            a[ex] = 0;
            a[ey] = ez;
        }
    }
    int q = 1;
    int p = 0;
    for (int i=0;i<63;i++){
        int num = 0;
        for (int j=1;j<=n;j++){
            if (q&a[j]){
                num += 1;
            }
        }
        if (num > n - num){
            p += q;
        }
        q = q << 1;
    }
    for (int i=1;i<=n;i++){
        cout << (int)(a[i]^p) << " ";
    }cout << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;

    while(test--){
        solve();
    }

    return 0;
}