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
#define umap(x, y) unordered_map<x, y, custom_hash>

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve(){

    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n&1){
        cout << -1 << endl;return;
    }
    vector<int> sames(26, 0);
    for (int i=0;i<(n/2);i++){
        if (s[i] == s[n-1-i]){
            sames[s[i]-'a'] += 1;
        }
    }
    int num_same = 0;
    for (int i=0;i<26;i++){
        num_same += min(1ll, sames[i]);
    }
    auto x = max_element(all(sames));
    int y = accumulate(all(sames), 0ll);
    int ans = 0;
    if (2*(*x) > y){
        // ans += 
        int extra = 2*(*x) - y;
        int ele = x - sames.begin();
        int avil = 0;
        for (int j=0;j<n/2;j++){
            if (s[j] != s[n-1-j] && (s[j] != ele+'a' && s[n-1-j] != ele+'a')){
                avil += 1;
            }
        }
        if (avil >= extra){
            ans += extra + y - *x;
        }else{
            cout << -1 << endl;return;
        }

    }else{
        if (y&1){
            // bool poss = 0;
            // for (int i=0;i<26 && !poss;i++){
            //     if (sames[i] != 0){
            //         for (int j=0;j<n/2;j++){
            //             if (s[j] != s[n-1-j] && (s[j] != i+'a' && s[n-1-j] != i+'a')){
            //                 poss = 1;
            //                 break;
            //             }
            //         }
            //     }
            // }
            // if (poss){
            //     ans += y/2 + 1;
            // }else{
            //     cout << -1 << endl;return;
            // }
            ans += max(0ll, (y-3)/2) + 2;
        }else{
            ans += y/2;
        }
    }
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