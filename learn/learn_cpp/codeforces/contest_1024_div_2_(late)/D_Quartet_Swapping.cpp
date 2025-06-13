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

int inversions(vi out){
    int n = out.size();
    vi a(n);
    for (int i=1;i<=n;i++){
        a[i-1] = i;
    }
    vector<int> pos(n+1);
    for (int i=0;i<n;i++){
        pos[out[i]] = i;
    }
    int inv = 0;
    for (int i=0;i<n;i++){
        inv += min(abs(i - pos[a[i]]), 1ll);
        int p1 = i;
        int p2 = pos[a[i]];
        int temp = out[i];
        swap(out[p1], out[p2]);
        pos[a[i]] = i;
        pos[temp] = p2;
    }
    return inv;
}   

void solve(){

    int n;
    cin >> n;

    vi even;
    vi odd;
    vi a(n);
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        a[i] = x;
        if (i&1){
            odd.push_back(x);
        }else{
            even.push_back(x);
        }
    }

    sort(rall(even));
    sort(rall(odd));
    vector<int> out1(n), out2(n);
    int o=0, e=0;
    for (int i=0;i<n;i++){
        // cout << "OUT: 1" << endl;
        // for (auto ele: out1){
        //     cout << ele << " ";
        // }cout << endl;
        if (n-i >= 4){
            if (i&1){
                out1[i] = odd.back();
                out2[i] = odd.back();
                odd.pop_back();

            }else{
                out1[i] = even.back();
                out2[i] = even.back();
                even.pop_back();
            }
        }else{
            if (even.size() == 1){
                out1[n-2] = even.back();
                out2[n-2] = even.back();
                even.pop_back();
                out1[n-3] = odd[0];
                out1[n-1] = odd[1];
                out2[n-3] = odd[1];
                out2[n-1] = odd[0];
            }else{
                out1[n-2] = odd.back();
                out2[n-2] = odd.back();
                even.pop_back();
                out1[n-3] = even[0];
                out1[n-1] = even[1];
                out2[n-3] = even[1];
                out2[n-1] = even[0];
            }
            break;
        }
    }
    // for (auto ele: out1){
    //         cout << ele << " ";
    //     }cout << endl;
    // for (auto ele: out2){
    //     cout << ele << " ";
    // }cout << endl;
    // vi ea((n+1)/2), eout1((n+1)/2), oa(n/2), oout1(n/2);
    // e = 0;
    // o = 0;
    // for (int i=0;i<n;i++){
    //     if (i&1){
    //         oa[o] = a[i];
    //         oout1[o++] = out1[i];
    //     }else{
    //         ea[e] = a[i];
    //         eout1[e++] = out1[i];
    //     }
    // }
    // for (auto ele: ea){
    //     cout << ele << " ";
    // }cout << endl;
    //  for (auto ele: eout1){
    //     cout << ele << " ";
    // }cout << endl;
    //  for (auto ele: oa){
    //     cout << ele << " ";
    // }cout << endl;
    //  for (auto ele: oout1){
    //     cout << ele << " ";
    // }cout << endl;
    int inv = inversions(a);
    int inv1 = inversions(out1);
    int inv2 = inversions(out2);
    // cout << inv << " " << inv1 << " " << inv2 << endl;
    if ((inv + inv1) % 2 == 0){
        for (auto ele: out1){
            cout << ele << " ";
        }
    }else{
        for (auto ele: out2){
            cout << ele << " ";
        }
    }
    cout << endl;

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