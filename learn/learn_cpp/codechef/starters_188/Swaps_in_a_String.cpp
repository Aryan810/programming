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

    vector<int> apos(n, n);
    for (int i=n-1;i>=0;i--){
        if (s[i] == 'A'){
            apos[i] = i;
        }else{
            if (i == n-1){
                apos[i] = n;
            }else{
                apos[i] = apos[i+1];
            }
        }
    }
    vector<int> cpos(n, -1);
    for (int i=0;i<n;i++){
        if (s[i] == 'C'){
            cpos[i] = i;
        }else{
            if (i == 0){
                cpos[i] = -1;
            }else{
                cpos[i] = cpos[i-1];
            }
        }
    }

    vector<int> cnta(n+1, 0);
    cnta[0] = 0;
    int cnt = 0;
    for (int i=0;i<n;i++){
        if (s[i] == 'A'){
            cnt += 1;
        }
        cnta[i+1] = cnt;
    }
    vector<int> cntc(n+1, 0);
    cntc[0] = 0;
    cnt = 0;
    for (int i=0;i<n;i++){
        if (s[i] == 'C'){
            cnt += 1;
        }
        cntc[i+1] = cnt;
    }
    int ans = 0;
    for (int i=0;i<n;i++){
        if (s[i] == 'B'){
            int l = cpos[i];
            int f;
            if (l == -1){
                f = cnta[i+1];
            }else{
                f = cnta[i+1] - cnta[l];
            }
            int r = apos[i];
            int sec;
            if (r == n){
                sec = cntc[n]-cntc[i];
            }else{
                sec = cntc[r+1] - cntc[i];
            }
            ans += max(sec, f);
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