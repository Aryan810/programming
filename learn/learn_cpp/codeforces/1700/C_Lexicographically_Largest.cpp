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
    multiset<int> bef;
    rep(i, n){
        b[i] = i + 1 + a[i];
        bef.insert(b[i]);
    }
    set<int> st;
    set<int> avail;

    for (int i=0;i<n;i++){
        if (st.find(b[i]) == st.end()){
            avail.insert(b[i]);
        }

        auto curr = *(--avail.upper_bound(b[i]));
        avail.erase(curr);
        st.insert(curr);
        if (st.find(curr-1) == st.end()){
            avail.insert(curr-1);
        }
    }

    // for (int i=(n-1);i>=0;i--){
    //     bef.erase(bef.find(b[i]));
    //     if (st.find(b[i]) != st.end()){
    //         avail.push(b[i]);
    //     }else if (bef.find(b[i]) != bef.end()){
    //         avail.push(b[i]);
    //         int sz = avail.size();
    //         while (sz--){
    //             int curr = avail.front();
    //             if (st.find(curr-1) != st.end() || bef.find(curr-1) != bef.end()){
    //                 avail.pop();
    //                 avail.push(curr-1);
    //             }else{
    //                 avail.pop();
    //                 st.insert(curr-1);
    //             }
    //         }
    //     }else{
    //         st.insert(b[i]);
    //         int sz = avail.size();
    //         while (sz--){
    //             int curr = avail.front();
    //             if (st.find(curr-1) != st.end() || bef.find(curr-1) != bef.end()){
    //                 avail.pop();
    //                 avail.push(curr-1);
    //             }else{
    //                 avail.pop();
    //                 st.insert(curr-1);
    //             }
    //         }
    //     }
    // }
    // cout << avail.front() << endl;
    auto it = --st.end();
    while (1){
        cout << *it << " ";
        if (it == st.begin()){
            break;
        }else{
            it--;
        }
    }
    cout << endl;
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