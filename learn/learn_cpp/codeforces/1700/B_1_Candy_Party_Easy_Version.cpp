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

void solve(){
    
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    int sm = accumulate(all(a), 0ll);
    if (sm%n != 0){
        cout << "No" << endl;return;
    }

    int avg = sm / n;
    vector<int> pos;
    vector<int> neg;
    for (int i=0;i<n;i++){
        int diff = abs(avg-a[i]);
        int temp = diff;
        while (diff > 0 && diff%2 == 0){
            // cout << diff << endl;
            diff /= 2;
        }
        diff += 1;
        while (diff > 0 && diff%2 == 0){
            // cout << diff << endl;
            diff /= 2;
        }
        if (diff != 1){
            cout << "No" << endl;return;
        }
        if (temp == 0){continue;}
        int f=-1, l=-1;
        for (int i=0;i<32;i++){
            if ((1ll<<i)&(temp)){
                if (f == -1){
                    f = i;
                }
                l = i;
            }
        }
        l++;
        if (avg > a[i]){
            pos.push_back((1ll<<l));
            neg.push_back((1ll<<f));
        }else{
            neg.push_back((1ll<<l));
            pos.push_back((1ll<<f));
        }
    }

    sort(all(pos));
    sort(all(neg));
    // for (auto ele: pos){
    //     cout << ele << " ";
    // }cout << endl;
    //  for (auto ele: neg){
    //     cout << ele << " ";
    // }cout << endl;
    if (pos == neg){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    
    

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