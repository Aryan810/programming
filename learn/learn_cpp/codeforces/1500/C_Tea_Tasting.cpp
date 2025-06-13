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

    vi a(n);
    rep(i, n){
        cin >> a[i];
    }
    vi b(n);
    rep(i, n){
        cin >> b[i];
    }
    vector<int> cum(n+1);
    cum[0] = 0;
    int sm = 0;
    for (int i=0;i<n;i++){
        sm += b[i];
        cum[i+1] = sm;
    }
    vector<int> l;
    vector<int> r;
    vector<int> extra(n, 0);
    for (int i=0;i<n;i++){
        auto it = lower_bound(all(cum), a[i]+cum[i]);
        if (it == cum.end()){
            l.push_back(i);
            r.push_back(n-1);
            continue;
        }
        if (it-cum.begin() == i+1){
            extra[i] += a[i];
            continue;
        }
        l.push_back(i);
        r.push_back(it-cum.begin()-2);
        int ext = a[i]-(cum[it-cum.begin()-1]-cum[i]);
        if (ext < 0){ext = 0;}
        extra[it-cum.begin()-1] += ext;
    }
    sort(all(l));
    sort(all(r));
    for (int i=0;i<n;i++){
        int x = upper_bound(all(l), i)-l.begin();
        int y = lower_bound(all(r), i)-r.begin();
        cout << (b[i]*(x-y) + extra[i]) << " ";
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