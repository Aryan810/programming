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
const int M = 1e9+7;
int binexpiter(int a, int b){
    if (a == 0){
        return 0;
    }
    int ans = 1;
    while (b){
        if (b&1){
            ans = (ans * a)%M;
        }
        a = (a * a)%M;
        b >>= 1;
    }
    return ans;
}
int facs[3*(100000) + 2];
int aFac_upon_bFac(int a, int b){
    return (facs[a]%M * binexpiter(facs[b], M-2)%M)%M;
}

int ncr(int n, int r){
    if (r == 0 || n < r){
        return 1;
    }
    // cout << n << " " << r << " " << n-r << endl;
    int ret = (facs[n]%M);
    // cout << facs[r] << " " << facs[n-r] << endl;
    ret = (ret * (binexpiter(facs[r], M-2)%M))%M;
    // cout << ret << endl;
    ret = (ret * binexpiter(facs[n-r], M-2)%M)%M;
    return ret;
}

void solve(){

    int n, k;
    cin >> n >> k;
    int left = n;
    for (int i=0;i<k;i++){
        int r, c;
        cin >> r >> c;
        if (r == c){
            left -= 1;
        }else{
            left -= 2;
        }
    }
    if (left&1){
        int ans = 0;
        for (int single=1;single<=left;single+=2){
            int doub = left-single;
            int temp = 1;
            temp = (temp * ncr(left, single))%M;
            temp = (temp * aFac_upon_bFac(doub, doub/2))%M;
            ans = (ans + temp)%M;
        }
        cout << ans << endl;
    }else{
        int ans = 0;
        // cout << left << endl;
        for (int single=0;single<=left;single+=2){
            int doub = left-single;
            int temp = 1;
            // cout << single << " " << ncr(left, single) << endl;
            temp = (temp * ncr(left, single))%M;
            temp = (temp * aFac_upon_bFac(doub, doub/2))%M;
            ans = (ans + temp)%M;
        }
        cout << ans << endl;
    }
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;
    int temp = 1;
    facs[0] = 1;
    facs[1] = 1;
    for (int i=1;i<=(3*100000);i++){
        facs[i] = (i * facs[i-1])%M;
    }
    while(test--){
        solve();
    }

    return 0;
}