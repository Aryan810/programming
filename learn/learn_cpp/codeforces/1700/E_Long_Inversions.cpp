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
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    for (int k=n;k>=1;k--){
        set<int> subpos;
        int counter = 0;
        bool done = 1;
        // cout << "-> " << k << endl;
        for (int i=0;i<n;i++){
            if (subpos.find(i) != subpos.end()){
                counter -= 1;
                subpos.erase(i);
            }
            int curr = ((s[i]-'0')+counter)%2;
            // cout << curr << " ";
            if (i < n-k+1){
                if (curr == 0){
                    counter += 1;
                    subpos.insert(i+k);
                }
            }else{
                if (curr == 0){
                    done = 0;
                }
            }
        }
        // cout << endl;
        if (done){
            cout << k << endl;return;
        }
    }


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