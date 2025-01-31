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

bool check(int mid, vi & a, vi & b){
    if (mid == -1){return 1;}
    for (int i=0;i<=mid;i++){
        if (a[i] >= b[a.size()-1+i-mid]){
            return 0;
        }
    }
    return 1;
}

void solve(){

    int n, m;cin >> n >> m;
    vi a(n);
    a[0] = 1;
    rep(i, n-1){
        cin >> a[i+1];
    }
    vi b(n);
    rep(i, n){
        cin >> b[i];
    }
    sort(all(a));
    sort(all(b));
    int low = 0;
    int high = n;
    while (high - low > 1){
        int mid = (low + high)/2;
        if (check(mid-1, a, b)){
            low = mid;
        }else{
            high = mid - 1;
        }
    }
    // cout << low << " - " << high << endl;
    if (check(high-1, a, b)){
        cout << (n - high) << endl;
    }else{
        cout << (n - low) << endl;
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