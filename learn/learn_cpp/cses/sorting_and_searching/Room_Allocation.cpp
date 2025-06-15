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
    vector<int> room(n);
    vector<array<int, 3> > v;
    for (int i=0;i<n;i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x, y, i});
    }

    set<pair<int, int> > st;
    set<int> avroom;
    sort(all(v));
    int mx = 0;
    for (int i=0;i<n;i++){
        auto & curr = v[i];
        // if (st.size() == 0){
        //     if (avroom.size() == 0){
        //         mx += 1;
        //         room[curr[2]] = mx;
        //     }else{
        //         int avr = *avroom.begin();
        //         room[curr[2]] = avr;
        //         avroom.erase(avroom.begin());
        //     }
        //     st.insert({curr[1], curr[2]});
        // }else{
            while (st.size() > 0 && st.begin()->first < curr[0]){
                auto it = st.begin();
                avroom.insert(room[it->second]);
                st.erase(st.begin());
            }
            if (avroom.size() == 0){
                mx += 1;
                room[curr[2]] = mx;
            }else{
                int avr = *avroom.begin();
                room[curr[2]] = avr;
                avroom.erase(avroom.begin());
            }
            st.insert({curr[1], curr[2]});
        // }
    }
    cout << mx << endl;
    for (int i=0;i<n;i++){
        cout << room[i] << " ";
    }cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    // int test;
    // cin >> test;

    // while(test--){
        solve();
    // }

    return 0;
}