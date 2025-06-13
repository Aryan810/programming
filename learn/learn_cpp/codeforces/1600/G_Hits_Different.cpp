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

int calcu(int a, int x, int n){
    int p = (n * (a - 1) * (a - 1)) + x*(a-1)*(n)*(n-1) + x*((n*(n+1))*(n*n + n - 2))/4;
    int q = ((((n*(n+1)*(2*n+1))/6) - n*(n+1) + n)*x*x) + (a-1)*((n*(n+1)*(2*n + 1))/6 + (n*(n+1))/2);
    int r = ((n*(n+1)*(2*n + 1)*(3*n*n + 3*n - 1))/30 + (n*(n+1)*(2*n + 1))/6 + (n*n*(n+1)*(n+1))/2)/4;
    return p + q + r;
}

void solve(){

    int n;
    cin >> n;
    int y = -1;
    for (int i=1;i<=2023;i++){
        if ((i*(i+1))/2 >= n){
            y = i;
            break;
        }
    }

    int pos = y - (y*(y+1))/2 + n;
    int k = y - pos + 1;
    int ans = 0;
    for (int i=0;i<k;i++){
        ans += calcu(1+(i*(i+1)/2), i, pos);
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