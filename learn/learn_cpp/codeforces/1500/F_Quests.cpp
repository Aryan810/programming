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

int check(int k, vi & a, int c, int d){
    if ((d)/(k+1) == 0){
        if (a[0] >= c){
            return 1;
        }else{
            return 0;
        }
    }
    int mxc = 0;
    for (int i=0;i<min(k+1, (int)a.size());i++){
        mxc += a[i] * ((d - i + k)/(k+1));
    }
    if (mxc >= c){return 1;}
    return 0;
}

void solve(){

    int n, c, d;
    cin >> n >> c >> d;
    vi a(n);
    rep(i, n) cin >> a[i];
    sort(rall(a));
    int mx =  a[0];
    if (mx*d < c){
        cout << "Impossible" << endl;return;
    }else if(c <= mx){
        cout << "Infinity" << endl;return;
    }else{
        int r = d+1;
        int l = 0;
        while (r-l > 1){
            int k = (r+l)/2;
            if (check(k, a, c, d)){
                l = k;
            }else{
                r = k - 1;
            }
        }
        // cout << check(2, a, c , d) << endl;
        if (check(r, a, c , d)){
            if (r >= d-1){cout << "Infinity" << endl;}else{
                cout << r << endl;
            }
        }else{
            if (l >= d-1){cout << "Infinity" << endl;}else{
                cout << l << endl;
            }
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