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
    unordered_map<int, int> m;
    rep(i, n){
        cin >> a[i];
        m[a[i]] += 1;
    }
    multiset<int> num;
    for (auto ele: m){
        num.insert(ele.second);
    }
    if (num.size() == 2){
        cout << (*(--num.end()) - *(num.begin())) << endl;
        return;
    }else if (num.size() == 1){
        cout << *(num.begin()) << endl;
        return;
    }
    while (1){
        auto a1 = (--num.end());
        auto b1 = --(--num.end());
        auto c1 = --(--(--num.end()));
        if (*c1 == 0){
            cout << *a1 - *b1 << endl;
            return;
        }
        // cout << *c1 << endl;
        int diff = *b1 - *c1 + 1;
        int aa = *a1 - diff;
        int bb = *b1 - diff;
        num.erase(--num.end());
        num.erase(--num.end());
        num.insert(aa);
        num.insert(bb);

        // for (auto ele: num){
        //     cout << ele << " ";
        // }cout << endl;
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