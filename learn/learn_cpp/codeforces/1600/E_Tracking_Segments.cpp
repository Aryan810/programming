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

bool check(vi & seg1, vi & seg2, int mid, vi & qri, int n){
    if (mid > qri.size()){
        mid = qri.size();
    }
    vector<int> q;
    set<int> temp;
    for (int i=0;i<(mid);i++){
        temp.insert(qri[i]);
    }
    for (auto ele: temp){
        q.push_back(ele);
    }
    for (int i=0;i<seg1.size();i++){
        int f = seg1[i];
        int s = seg2[i];
        auto a = lower_bound(all(q), f);
        auto b = upper_bound(all(q), s);
        // if (2 * (int)(b - a) > s-f+1){
        //     return 1;
        // }
        int total = s-f+1;
        int ones = b-a;

        if (ones >= total/2 + 1){
            return 1;
        }
    }
    return 0;

    // vector<int> a(n, 0);
    // for (int i=0;i<mid;i++){
    //     a[qri[i]-1] = 1;
    // }

    // vector<int> b(n+1, 0);
    // b[0] = 0;
    // int sm = 0;
    // for (int i=0;i<n;i++){
    //     sm += a[i];
    //     b[i+1] = sm;
    // }

    // for (int i=0;i<seg1.size();i++){
    //     int ones = b[seg2[i]] - b[seg1[i]-1];
    //     if (ones >= (seg2[i]-seg1[i]+1)/2 + 1){
    //         return 1;
    //     }
    // }
    // return 0;
}

void solve(){

    int n, m;cin >> n >> m;
    vector<int> seg1(m);
    vector<int> seg2(m);
    for (int i=0;i<m;i++){
        cin >> seg1[i] >> seg2[i];
    }
    int q;
    cin >> q;
    vi qri(q);
    rep(i, q) cin >> qri[i];
    int l = 0;
    int h = n;

    while (h-l > 1){
        int mid = (h + l)/2;
        if (check(seg1, seg2, mid, qri, n)){
            h = mid;
        }else{
            l = mid + 1;
        }
    }

    if (check(seg1, seg2, l, qri, n)){
        cout << l << endl;
    }else if (check(seg1, seg2, h, qri, n)){
        cout << h << endl;
    }else{
        cout << -1 << endl;
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