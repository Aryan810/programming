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

    int k;
    cin >> k;

    vector<pair<int, int> > points;
    int cx = -1e8,cy = -1e8;
    while (k > 0){
        int x = (sqrt(8*k + 1) + 1)/2;
        for (int i=0;i<x;i++){
            points.push_back({cx, cy});
            cy += 1;
        }
        k -= (x*(x-1))/2;
        cx += 1;
    }
    cout << points.size() << endl;
    for (int i=0;i<points.size();i++){
        cout << points[i].first << " " << points[i].second << endl;
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