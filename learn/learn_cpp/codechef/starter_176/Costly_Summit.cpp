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

void logic(vector<int> & num, int c, int i, int learnt, int translated, int & ans){
    if (i >= 5){ans = min(ans, (c*learnt)+((translated*(translated+1))/2));return;}
    
    if (num[i] != 0){
        // learn it
        logic(num, c, i+1, learnt+1, translated, ans);

        // translated all
        logic(num, c, i+1, learnt, translated+num[i], ans);
    }else{
        // learn it
        logic(num, c, i+1, learnt, translated, ans);

        // translated all
        logic(num, c, i+1, learnt, translated, ans);
    }

}

void solve(){

    int n, c;cin >> n >> c;
    vector<int> num(5);
    // ANS = 1e18;
    for (int i=0;i<n;i++){
        char x;
        cin >> x;
        num[x-'A'] += 1;
    }
    int ans = 1e18;
    logic(num, c, 0, 0, 0, ans);

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