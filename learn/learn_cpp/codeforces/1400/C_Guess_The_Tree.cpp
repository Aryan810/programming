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

    // vector<vector<int> > graph(n+1);
    vector<pair<int, int> > out;
    for (int i=1;i<=(n-1);i++){
        int f = i;
        int s = n;
        while (1){
            cout << "? " << f << " " << s << endl;cout.flush();
            int res;
            cin >> res;
            if (res == f){
                // graph[f].push_back(s);
                // graph[s].push_back(f);
                out.push_back({f, s});
                break;
            }
            s = res;
        }
    }
    cout << "! ";
    for (auto ele: out){
        cout << ele.first << " " << ele.second << " ";
    }cout << endl;cout.flush();

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