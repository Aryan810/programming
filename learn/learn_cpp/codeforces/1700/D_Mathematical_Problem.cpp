// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>
const int M = 1e9 + 7;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

vector<vector<string> > dp(100);

void solve(){
    int n;
    cin >> n;
    
    for (int i=5;i<=n;i+=2){
        if (dp[i].size() > 0){
            continue;
        }else{
            auto & a = dp[i-2];
            for (int j=0;j<(i-2);j++){
                dp[i].push_back(a[j] + "00");
            }
            string s1 = "9";
            string s2 = "1";
            for (int j=0;j<(i-3)/2;j++){
                s1.push_back('0');
                s2.push_back('0');
            }
            s1.push_back('6');
            s2.push_back('6');
            for (int j=0;j<(i-3)/2;j++){
                s1.push_back('0');
                s2.push_back('0');
            }
            s1.push_back('1');
            s2.push_back('9');
            dp[i].push_back(s1);
            dp[i].push_back(s2);
        }
    }

    for (auto & ele: dp[n]){
        cout << ele << endl;
    }
    

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test;
    cin >> test;
    dp[1].push_back("1");
    dp[3].push_back("196");
    dp[3].push_back("961");
    dp[3].push_back("169");
    while(test--){
        solve();
    }

    return 0;
}