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

struct dsu{
    int n;
    vector<int> parent, set_size;
    dsu(int n){
        this->n = n;

        parent.resize(n);

        set_size.resize(n);

        for (int i = 0; i < n; i++){

            parent[i] = i;

            set_size[i] = 1;
        }
    }
    int find(int v){
        if(v == parent[v]) return v;
        return parent [v] = find (parent [v]);
    }
    void set_union (int a, int b){
        a = find(a);
        b = find (b);
        if(a != b){
            if(set_size[a] < set_size [b]){
                swap (a, b) ;
            }
            parent[b] = a;
            set_size[a] += set_size[b];
        }   
    }
};

void solve(){

    int n, x;
    cin >> n >> x;
    if (n == 1 && x == 0){
        cout << -1 << endl;return;
    }
    if (x == 0){
        if (n&1){
            cout << n+3 << endl;
        }else{
            cout << n << endl;
        }
        return;
    }

    string s;
    int one = 0;
    for (int i=0;i<32;i++){
        if (x&(1ll << i)){
            s.push_back('1');
            one += 1;
        }else{
            s.push_back('0');
        }
    }
    while (s.back() == '0'){
        s.pop_back();
    }

    if (n <= one){
        cout << x << endl;return;
    }

    // int extra = n - one;
    // if (s[0] == '0'){
    //     if (extra&1){cout << x + (extra + 1) << endl;}else{
    //         cout << x + extra << endl;
    //     }
    // }else{
    //     if (extra&1){
    //         cout << x + extra + 3 << endl;
    //     }else{
    //         cout << x + extra << endl;
    //     }
    // }

    if (x == 1){
        if (n&1){
            cout << n << endl;
        }else{
            cout << n+3 << endl;
        }
    }else{
        if (n&1){
            cout << x + n - (one&1?one:one-1) << endl;
        }else{
            cout << x + n - (one&1?one-1:one) << endl;
        }
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