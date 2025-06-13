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
    set<pair<int, int> > ss;
    rep(i, n){
        int x;
        cin >> x;
        ss.insert({x, i});
    }
    vector<pair<int, int> > out;
    int sm = 0;
    while (1){
        auto l = --ss.end();
        auto sl = --(--ss.end());
        if (l->first > 0 && sl->first > 0){
            auto temp = *l;
            auto temp1 = *sl;
            temp.first -= 1;
            temp1.first -= 1;
            out.push_back({temp.second, temp1.second});
            sm += 1;
            ss.erase(--ss.end());
            ss.erase(--ss.end());
            ss.insert(temp);
            ss.insert(temp1);
        }else{
            break;
        }
    }
    cout << sm << endl;
    for (auto ele: out){
        cout << ele.first+1 << " " << ele.second+1 << endl;
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