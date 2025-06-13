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
    vector<pair<int, int> > fora;
    int curr = -1;
    rep(i, n){
        int x;
        cin >> x;
        int num = 1;
        while (x%m == 0){
            x /= m;
            num *= m;
        }
        // cout << curr << " " << x << " " << num << endl;
        if (curr == -1){
            curr = x;
            fora.push_back({x, num});
        }else if(x == curr){
            fora.back().second += num;
        }else{
            curr = x;
            fora.push_back({x, num});
        }
    }
    // for (auto ele: fora){
    //     cout << ele.first << " " << ele.second << endl;
    // }
    int k;cin >> k;
    curr = -1;
    vector< pair<int, int> > forb;
    rep(i, k){
        int x;
        cin >> x;
        int num = 1;
        while (x%m == 0){
            x /= m;
            num *= m;
        }
        // cout << curr << " " << x << " " << num << endl;
        if (curr == -1){
            curr = x;
            forb.push_back({x, num});
        }else if(x == curr){
            forb.back().second += num;
        }else{
            curr = x;
            forb.push_back({x, num});
        }
    }
    cout << ((forb == fora)?"Yes":"No") << endl;

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