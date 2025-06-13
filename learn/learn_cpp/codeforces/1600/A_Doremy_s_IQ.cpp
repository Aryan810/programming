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

bool check(int mid, vi & a, int q){
    if (a[mid-1] <= q){
        return 0;
    }
    if (mid == a.size()){return 1;}
    q -= 1;
    for (int i=mid;i<a.size();i++){
        if (q <= 0){
            return 0;
        }
        if (a[i] > q){
            q -= 1;
        }
    }
    return q > 0;
}


void solve(){

    int n, q;
    cin >> n >> q;

    vi a(n);
    map<int, int> num;
    int good = 0;
    rep(i, n){
        int x;
        cin >> x;
        num[x] += 1;
        a[i] = x;
        if (x <= q){
            good += 1;
        }
    }
    string out;
    for (int i=0;i<n;i++){
        out.push_back('0');
    }

    // for (int i=0;i<n;i++){
    //     num[a[i]] -= 1;
    //     if (q == 0){break;}
    //     if (a[i] <= q){
    //         out[i] = '1';
    //     }else{
    //         if (!(num.find(q) != num.end() && num[q] > 0)){
    //             out[i] = '1';
    //             q -= 1;
    //         }
    //     }
    // }
    // cout << out << endl;

    int tmp = 0;
    for (int i=n-1;i>=0;i--){
        if (a[i] <= tmp){
            out[i] = '1';
        }else{
            if (tmp < q){
                tmp += 1;
                out[i] = '1';
            }
        }
    }
    cout << out << endl;
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