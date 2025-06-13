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

    int n;cin >> n;int m;cin >> m;
    vi a(n);
    map<int, int> temp;
    rep(i, n){
        int x;cin >> x;
        temp[x] += 1;
    }
    vector<pair<int, int> > num;
    for (auto ele: temp){
        num.push_back({ele.first, ele.second});
    }
    sort(rall(num), [](pair<int, int> a, pair<int, int> b){
        return (a.second < b.second);
    });
    while (num.size() > 0 && m >= num.back().second){
        m -= num.back().second;
        num.pop_back();
    }
    cout << ((num.size() == 0)?1:num.size()) << endl;

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