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
    int fpos = n;
    rep(i, n){
        int x;
        cin >> x;
        a[i] = x;
        if (x > 0 && fpos == n){
            fpos = i;
        }
    }
    vi out(n);
    vector<pair<int, int> > opers;
    if (fpos == 0){
        out[0] = 32*a[0];
        for (int i=0;i<5;i++){opers.push_back({1, 1});}
        for (int i=1;i<n;i++){
            out[i] = 2*out[i-1] + a[i];
            opers.push_back({i+1, i});
            opers.push_back({i+1, i});
        }
    }else if (fpos == 1){
        out[0] = a[0];
        out[1] = 32*a[1];
        for (int i=0;i<5;i++){opers.push_back({2, 2});}
        for (int i=2;i<n;i++){
            out[i] += 2*out[i-1] + a[i];
            opers.push_back({i+1, i});
            opers.push_back({i+1, i});
        }
    }else{
        out[fpos-1] = a[fpos-1];
        for (int i=fpos-2;i>=0;i--){
            out[i] += out[i+1] + a[i];
            opers.push_back({i+1, i+2});
        }
        if (fpos < n-1){
            out[fpos] = 32*a[fpos];
            for (int i=0;i<5;i++){opers.push_back({fpos+1, fpos+1});}
            for (int i=fpos+1;i<n;i++){
                out[i] += 2*out[i-1] + a[i];
                opers.push_back({i+1, i});
                opers.push_back({i+1, i});
            }
        }
    }
    cout << opers.size() << endl;
    for (auto ele: opers){
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