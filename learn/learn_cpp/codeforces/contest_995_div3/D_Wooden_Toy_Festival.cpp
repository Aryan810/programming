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

bool check(int mid, vi & a){
    int carver = 1;
    int low = -1, high = -1;
    int i = 0;
    // cout << "MID: " << mid << endl;
    while (i < a.size() && carver <= 3){
        // cout << low << " : " << high << " >> " << carver << " Ai: " << a[i] << endl;
        if (low == -1){
            low = a[i]-mid;
        }
        if (high == -1){
            high = a[i]+mid;
        }
        low = max(low, a[i]-mid);
        high = min(high, a[i]+mid);
        if (low > high){
            carver += 1;
            low = a[i]-mid;
            high = a[i]+mid;
        }
        i++;
    }
    if (carver <= 3){
        return 1;
    }else{
        return 0;
    }
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    sort(rall(a));

    int low = 0;
    int high = a[0] - a[n-1];
    while (high - low > 1){
        int mid = (low + high)/2;
        if (check(mid, a)){
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    if (check(low, a)){
        cout << low << endl;
    }else{
        cout << high << endl;
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