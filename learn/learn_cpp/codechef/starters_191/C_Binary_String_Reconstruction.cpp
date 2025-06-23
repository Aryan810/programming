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

void solve(){
    
    string s;
    cin >> s;

    int x;
    cin >> x;
    int n = s.size();
    vi w(s.size(), -1);
    for (int i=0;i<n;i++){
        int r = i+x;
        int l = i-x;
        if (r >= n && l < 0){
            if (s[i] == '1'){
                cout << -1 << endl;return;
            }
        }else if (r >= n){
            if (w[l] != (1 - (s[i]-'0'))){w[l] = s[i]-'0';}else{
                cout << -1 << endl;return;
            }
        }else if (l < 0){
            if (w[r] != (1 - (s[i]-'0'))){w[r] = s[i]-'0';}else{
                cout << -1 << endl;return;
            }
        }else if (s[i] == '0'){
            if (w[l] != 1){w[l] = 0;}else{
                cout << -1 << endl;return;
            }
            if (w[r] != 1){w[r] = 0;}else{
                cout << -1 << endl;return;
            }
        }
    }
    for (int i=x;i<(n-x);i++){
        if (s[i] == '1'){
            if (w[i-x] == 0){
                if (w[i+x] == 0){cout << -1 << endl;return;}else{w[i+x] = 1;}
            }else if (w[i+x] == 0){
                if (w[i-x] == 0){cout << -1 << endl;return;}else{w[i-x] = 1;}
            }
        }
    }
    for (auto & ele: w){
        if (ele != 0 && ele != 1){
            cout << 1;
        }else{
            cout << ele;
        }
    }cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}