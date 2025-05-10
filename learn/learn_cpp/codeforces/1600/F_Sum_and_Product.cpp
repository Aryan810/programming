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

int bsqrt(int n){
    int l = 1;
    int h = n;
    while (h - l > 1){
        int mid = (l + h)/2;

        if (mid * mid == n){
            return mid;
        }else if (mid*mid > n){
            h = mid - 1;
        }else{
            l = mid + 1;
        }
    }

    if (l * l == n){
        return l;
    }else if (h * h == n){
        return h;
    }else{
        return -1;
    }
}

void solve(){

    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    int q;
    cin >> q;
    for (int i=0;i<q;i++){
        int x, y;
        cin >> x >> y;
        int p = bsqrt(x);
        int r = 
        
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