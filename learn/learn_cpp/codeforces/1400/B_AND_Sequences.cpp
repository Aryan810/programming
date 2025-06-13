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
int M = 1e9 + 7;
void solve(){

    int n;
    cin >> n;

    vi a(n);
    map<int, int> m;
    int same = -1;
    rep(i, n){
        int x;
        cin >> x;
        if (same == -1){
            same = x;
        }
        same = same&x;
        m[x] += 1;
    }
    vector<pair<int, int> > num;
    for (auto ele: m){
        num.push_back({ele.first, ele.second});
    }
    sort(rall(num), [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    });
    // cout << same << endl;
    int ans = 0;
    for (int i=0;i<num.size();i++){
        if (num[i].first == same){
            int fact = 1;
            for (int i=2;i<=(n-2);i++){
                fact = (fact * i%M)%M;
            }
            ans = fact;
            ans = (ans * num[i].second%M)%M;
            ans = (ans * (num[i].second - 1)%M)%M;
        }
    }
    cout << ans << endl;

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