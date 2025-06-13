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
int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}
void solve(){

    int n, k;cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    string ans = "1";
    for (int i=0;i<n;i++){
        string x = to_string(a[i]);
        vector<int> placevalues(37, 0);
        for (int j=0;j<ans.size();j++){
            for (int l=0;l<x.size();l++){
                int y = (ans[j]-'0')*(x[l]-'0');
                placevalues[x.size()-l-1 + ans.size()-j-1] += y;
            }
        }
        for (int i=0;i<36;i++){
            placevalues[i+1] += placevalues[i]/10;
            placevalues[i] = placevalues[i]%(10);
        }
        int lastnonzero = 0;
        for (int i=0;i<37;i++){
            if (placevalues[i] != 0){
                lastnonzero = max(lastnonzero, i);
            }
        }
        if (lastnonzero >= k){
            ans = "1";
        }else{
            ans = "";
            for (int i=lastnonzero;i>=0;i--){
                ans = ans + char(placevalues[i]+'0');
            }
        }
        // cout << ans << endl;


    }
    cout << ans << endl;
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  
        solve();
   
    return 0;
}