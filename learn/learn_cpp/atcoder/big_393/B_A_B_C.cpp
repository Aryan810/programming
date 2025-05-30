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

    string s;
    cin >> s;

    int ans = 0;
    for (int i=0;i<s.size();i++){
        if (s[i] == 'A'){
            for (int j=i+1;j<s.size();j++){
                if (s[j] == 'B'){
                    // cout << i << " " << j << endl;
                    if ((2*j-i < s.size()) && s[j + j - i] == 'C'){
                        ans += 1;
                    }
                }
            }
        }
    }
    cout << ans << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        solve();

    return 0;
}