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
    vi a(n);
    rep(i, n) cin >> a[i];
    vi b(n);
    rep(i, n) cin >> b[i];
    vector<pair<int,int> > ind(2*n + 2);
    for (int i=0;i<n;i++){
        ind[a[i]] = {i, 0};
        ind[b[i]] = {i, 1};
    }
    vector<pair<int, int> > out;
    for (int i=0;i<n;i++){
        if (a[i] != i+1){
            while (ind[i+1].first != i || ind[i+1].second != 0){
                // cout << ind[i+1].first << " " << ind[i+1].second << endl;
                if (ind[i+1].second == 1){
                    // cout << "HER" << endl;
                    int prev = a[ind[i+1].first];
                    a[ind[i+1].first] = i+1;
                    b[ind[i+1].first] = prev;
                    out.push_back({3, ind[i+1].first + 1});
                    ind[i+1].second = 0;
                    ind[prev].second = 1;
                }else{
                    int prev = a[ind[i+1].first - 1];
                    swap(a[ind[i+1].first], a[ind[prev].first]);
                    out.push_back({1, ind[i+1].first});
                    ind[i+1].first -= 1;
                    ind[prev].first += 1;
                }
            }
        }
        if (b[i] != n+i+1){
            // cout << "b:" << i << endl;
            while (ind[n+i+1].first != i || ind[n+i+1].second != 1){
                if (ind[n+i+1].second == 0ll){
                    int prev = b[ind[n+i+1].first];
                    b[ind[n+i+1].first] = n+i+1;
                    a[ind[n+i+1].first] = prev;
                    out.push_back({3, ind[n+i+1].first + 1});
                    ind[n+i+1].second = 1;
                    ind[prev].second = 0;
                }else{
                    int prev = b[ind[n+i+1].first - 1];
                    swap(b[ind[n+i+1].first], b[ind[prev].first]);
                    out.push_back({2, ind[n+i+1].first});
                    ind[n+i+1].first -= 1;
                    ind[prev].first += 1;
                }
            }
        }
    }
    cout << out.size() << endl;
    for (auto ele: out){
        cout << ele.first << " " << ele.second << endl;
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