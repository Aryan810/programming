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
    rep(i, n) cin >> a[i];
    vector<pair<int, int> > oper;
    int fpos = 0;
    while (fpos < n && a[fpos] <= 0){
        fpos += 1;
    }
    int nsum = 0;
    for (int i=fpos-2;i>=0;i--){
        a[i] += a[i+1];
        oper.push_back({i+1, i+2});
    }
    if (fpos < n){
        a[fpos] *= 32;
        for (int i=0;i<5;i++){
            oper.push_back({fpos+1, fpos+1});
        }
        for (int i=fpos + 1;i<n;i++){
            a[i] += 2*a[i-1];
            oper.push_back({i+1, i});
            oper.push_back({i+1, i});
        }
    }
    cout << oper.size() << endl;
    for (auto ele: oper){
        cout << ele.first << " " << ele.second << endl;
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