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
    int zero = 0;
    rep(i, n){
        int x;
        cin >> x;
        if (x == 0){
            zero += 1;
        }
        a[i] = x;
    }
    if (zero == 0){
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
        return;
    }
    if (a[0] != 0){
        cout << 2 << endl;
        cout << 2 << " " << n << endl;
        cout << 1 << " " << 2 << endl;return;
    }

    if (a[n-1] != 0){
        cout << 2 << endl;
        cout << 1 << " " << n-1 << endl;
        cout << 1 << " " << 2 << endl;return;
    }

    vector<pair<int, int> > out;

    out.push_back({n-1, n});
    out.push_back({1, 2});
    zero = 0;
    for (int i=2;i<(n-2);i++){
        if (a[i] == 0){
            zero += 1;
        }
    }

    if (zero == 0){
        out.push_back({1, n-2});
    }else{
        out.push_back({2, n-2});
        out.push_back({1, 2});
    }

    cout << out.size() << endl;
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