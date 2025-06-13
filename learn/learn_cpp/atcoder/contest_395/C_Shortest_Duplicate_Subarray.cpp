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
    map<int, vector<int> > pos;
    rep(i, n){
        int x;
        cin >> x;
        pos[x].push_back(i);
    }

    int ans = 1e18;
    int num = -1;
    for (auto ele: pos){
        if (ele.second.size() > 1){
            ans = min(ans, ele.second[1]-ele.second[0]+1);
            num = ele.first;
        }
    }

    if (num == -1){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}