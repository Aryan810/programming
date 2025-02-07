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

    int n, k;
    cin >> n >> k;
    int a = log2(n);
    vector<pair<int, int> > out;
    if (k == n-1){
        if (n == 4){cout << -1 << endl;return;}
        out.push_back({n-1, n-2});
        out.push_back({0, 1});
        int b = (pow(4, (a+1)/2)-1)/3;
        out.push_back({b, n-b});
        out.push_back({n-1-b, b-1});
        for (int i=0;i<n/2;i++){
            if (!((i == 1 || i == 0) || (i == b || (i == n-b || (i == n-1-b || i == b-1))))){
                out.push_back({i, n-1-i});
            }
        }
        for (auto ele: out){
            cout << ele.first << " " << ele.second << endl;
        }
        return;
    }else if (k == 0){
        for (int i=0;i<n/2;i++){
            cout << i << " " << n-1-i << endl;
        }
        return;
    }
    out.push_back({k, n-1});
    out.push_back({0, n-1-k});
    for (int i=0;i<n/2;i++){
        if (!((i == k || i == 0) || i == (n-1-k))){
            out.push_back({i, n-1-i});
        }
    }
    for (auto ele: out){
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