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

bool isprime(int x){
    if (x == 1){return 0;}
    if (x == 2){return 1;}
    for (int i=2;(i*i)<=x;i++){
        if (x%i == 0){
            return 0;
        }
    }
    return 1;
}

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

    int n, k;
    cin >> n >> k;
    if (k == 1){
        cout << (isprime(n)?"YES":"NO") << endl;return;
    }
    if (n == 1){
        int x = 0;
        for (int i=0;i<k;i++){
            x += binexpiter(10, i);
        }
        cout << (isprime(x)?"YES":"NO") << endl;return;
    }

    if (!isprime(n)){
        cout << "NO" << endl;return;
    }
    if (k == 3 || k == 6){
        cout << "NO" << endl;return;
    }

    
    cout << "NO" << endl;


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