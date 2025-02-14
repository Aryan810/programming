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
    vi a(n), b(m);
    int mn = 1e18;
    rep(i, n){cin >> a[i];}
    int ind = 0;
    rep(i, m){
        int x;
        cin >> x;
        if (x < mn){
            mn = x;
            ind = i;
        }
        b[i] = x;
    }
    vi p1, p2;
    int chn = -1;
    for (int i=0;i<(n-m);i++){
        if (chn >= i || a[i] > mn){a[i] = mn;chn = i+m-1;}
        p1.push_back(a[i]);
        p2.push_back(a[i]);
    }
    
    if (mn < a[n-m] || chn >= n-m){
        for (int i=0;i<(n-m);i++){
            cout << p1[i] << " ";
        }
        for (int i=0;i<m;i++){
            cout << b[(ind+i)%m] << " ";
        }cout << endl;
    }else{
        for (int i=0;i<(m);i++){
            p1.push_back(a[i+n-m]);
            p2.push_back(b[(ind+i)%m]);
        }
        if (p1 < p2){
            for (auto ele: p1){
                cout << ele << " ";
            }
        }else{
            for (auto ele: p2){
                cout << ele << " ";
            }
        }
        cout << endl;
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