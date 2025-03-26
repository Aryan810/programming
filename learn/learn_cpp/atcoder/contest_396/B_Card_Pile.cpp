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

    int q;
    cin >> q;

    stack<int> s;
    for (int i=0;i<100;i++){s.push(0);};

    rep(i, q){
        int t, x;
        cin >> t;
        if (t == 1){
            cin >> x;
            s.push(x);
        }else{
            cout << s.top() << endl;
            if (!s.empty()){s.pop();}
        }
    }

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;

    while(test--){
        solve();
    }

    return 0;
}