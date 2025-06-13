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

void solve(){
    int n, l, r;
    cin >> n >> l >> r;
    vi a(n);
    vector<int> al;
    vector<int> right;
    vector<int> left;
    int ansd = 0;
    rep(i, n){
        int x;
        cin >> x;
        a[i] = x;
        al.push_back(x);
        if (i < l-1){
            left.push_back(x);
        }else if (i >= r){
            right.push_back(x);
        }
    }
    sort(all(al));
    sort(all(right));
    sort(all(left));
    map<int, int> cnt;
    for (int i=0;i<(r-l+1);i++){
        cnt[al[i]] += 1;
    }
    vector<int> bad;
    for (int i=l-1;i<r;i++){
        if (cnt[a[i]] == 0){
            bad.push_back(a[i]);
        }else{
            ansd += a[i];
            cnt[a[i]] -= 1;
        }
    }

    sort(rall(bad));
    // cout << "bad" << endl;
    // for (auto ele: bad){
    //     cout << ele << " ";
    // }cout << endl;
    // cout << "left" << endl;

    // for (auto ele: left){
    //     cout << ele << " ";
    // }cout << endl;
    // cout << "right" << endl;

    // for (auto ele: right){
    //     cout << ele << " ";
    // }cout << endl;

    // right
    int ansr = 0;
    int i=0;
    while (i < bad.size() && i < right.size()){
        ansr += min(bad[i], right[i]);
        i += 1;
    }
    while (i < bad.size()){
        ansr += bad[i];
        i += 1;
    }

    int ansl = 0;
    i = 0;
    while (i < bad.size() && i < left.size()){
        ansl += min(bad[i], left[i]);
        i += 1;
    }
    while (i < bad.size()){
        ansl += bad[i];
        i += 1;
    }
    cout << min(ansl, ansr) + ansd << endl;

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