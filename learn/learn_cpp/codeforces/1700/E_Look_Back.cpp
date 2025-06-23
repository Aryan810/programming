// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>
const int M = 1e9 + 7;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
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
int calc(int a, int b, int num){
    int req;
    if (a > b){
        req = num;
        while (b*binexpiter(2, req-num) < a){
            req += 1;
        }
    }else if (a < b){
        req = num;
        while (1){
            if (a*binexpiter(2, num-req+1) > b){
                break;
            }
            req -= 1;
        }
    }else{
        req = num;
    }
    return req;
}

void solve(){
    
    int n;
    cin >> n;

    vi a(n);
    rep(i, n) cin >> a[i];
    int oper = 0;
    int num = 0;
    for (int i=1;i<n;i++){
        int req = max(calc(a[i-1], a[i], num), 0ll);
        // cout << req << endl;
        num = req;
        oper += req;
    }
    cout << oper << endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}