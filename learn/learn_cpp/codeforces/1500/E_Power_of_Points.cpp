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
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    rep(i, n){
        int x;cin >> x;
        a[i] = x;
        b[i] = x;
    }

    sort(all(b));
    int sames = 0;
    unordered_map<int, int, custom_hash> ans;
    int cumLeft[n+1];cumLeft[0] = 0;
    int cumRight[n+1];cumRight[0] = 0;
    int s1 = 0, s2 = 0;
    for (int i=0;i<n;i++){
        if (i < n-1 && b[i] == b[i+1]){
            sames += 1;
        }
        if (i == 0){
            s1 += 0;
        }else{
            s1 += (b[i]-b[i-1])*(n-i);
            if (b[i]-b[i-1] == 0){
                s1 += 1;
            }
        }
        cumLeft[i+1] = s1;

        if (i == n-1){
            s2 += 0;
        }else{
            s2 += (b[i+1]-b[i])*(i+1);
            if (b[i+1]-b[i] == 0){
                s2 += 1;
            }
        }
        cumRight[i+1] = s2;
    }
    for (int i=0;i<n;i++){
        ans[b[i]] = cumLeft[n]-cumLeft[i+1] + cumRight[i] + n - sames;
    }
    for (auto ele: a){
        cout << ans[ele] << " ";
    }cout << endl;
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