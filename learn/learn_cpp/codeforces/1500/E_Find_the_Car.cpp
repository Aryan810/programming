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

    int n, k, q;
    cin >> n >> k >> q;

    vi a(k+1);
    a[0] = 0;
    vi b(k+1);
    b[0] = 0;

    for (int i=0;i<k;i++){
        cin >> a[i+1];
    }

    for (int i=0;i<k;i++){
        cin >> b[i+1];
    }

    for (int i=0;i<q;i++){
        int d;
        cin >> d;
        auto it = lower_bound(all(a), d);
        if (*it == d){
            cout << b[it-a.begin()] << " ";
        }else{
            int x = b[it-a.begin()-1] + ((d - *(it-1))*(b[it-a.begin()]-b[it-a.begin()-1]))/(*it - *(it-1));
            cout << x << " ";
        }
    }
    cout << endl;
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