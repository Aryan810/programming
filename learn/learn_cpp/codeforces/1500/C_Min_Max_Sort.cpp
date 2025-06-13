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

    int n;cin >> n;
    vi a(n);
    unordered_map<int, int, custom_hash> place;
    rep(i, n){
        int x;
        cin >> x;
        place[x] = i;
        a[i] = x;
    }
    int i = -1;
    int j = -1;
    if (n&1){
        i = place[(n+1)/2];
        j = i;
    }else{
        i = place[(n)/2];
        j = place[n/2 + 1];
    }
    int found = (i <= j)?1:0;
    // cout << "FOUND: " << found << endl;
    while ((i >= 0 && j < n) && (i <= j)){
        if (place[a[i]-1] < i && place[a[j] + 1] > j){
            found += 1;
            i = place[a[i]-1];
            j = place[a[j]+1];
        }else{
            break;
        }
    }
    if (n&1){
        cout << ((n+1)/2 - found) << endl;
    }else{
        cout << (n/2 - found) << endl;
    }

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