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

    int n, m;
    cin >> n >> m;

    vi b(n), w(m);

    rep(i, n) cin >> b[i];
    rep(i, m) cin >> w[i];
    sort(rall(b));sort(rall(w));
    int i=0, j=0;
    int sum = 0;
    while (i < n && j < m){
        if (w[j] > 0 && b[i] + w[j] >= 0){
            sum += b[i] + w[j];
            i += 1;
            j += 1;
        }else{
            break;
        }
    }

    for (int l=i;l<n;l++){
        if (b[l] > 0){
            sum += b[l];
        }else{
            break;
        }
    }
    cout << sum << endl;
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