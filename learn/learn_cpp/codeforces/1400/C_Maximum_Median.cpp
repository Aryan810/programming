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

    int n, k;cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    sort(rall(a));
    for (int i=0;i<n/2;i++){
        a.pop_back();
    }
    sort(all(a));
    n = a.size();
    int j = 0;
    int sum = 0;
    bool fullGone = 1;
    for (int i=0;i<n-1;i++){
        sum += (i+1)*(a[i+1] - a[i]);
        if (k > sum){
            j += a[i+1] - a[i];
            continue;
        }else if (k == sum){
            j += a[i+1] - a[i];
            cout << j+a[0] << endl;return;
            fullGone = 0;
        }else{
            j += (k - sum + (i+1)*(a[i+1]-a[i]))/(i+1);
            cout << j+a[0] << endl;return;
            fullGone = 0;
        }
    }
    if (fullGone){
        if(k > sum){
            j += (k - sum)/n;
        }
    }
    cout << j+a[0] << endl;
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve();

    return 0;
}