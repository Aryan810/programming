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

    int n;
    cin >> n;

    vi a(n);
    map<int ,int> num;
    rep(i, n){
        int x;
        cin >> x;
        num[x] += 1;
        a[i] = x;
    }

    vector<pair<int, int> > cnt;
    for (auto ele: num){
        if (ele.second >= 2){cnt.push_back({ele.first, ele.second});}
    }
    sort(rall(cnt));
    // for (auto ele: cnt){
    //     cout << ele.first << " " << ele.second << endl;
    // }
    vector<int> corr(4, 0);
    vector<int> seted(4, 0);

    for (int i=0;i<cnt.size();i++){
        if (cnt[i].second >= 4 && (!seted[0] && !seted[2])){
            if (!seted[0]){corr[0] = cnt[i].first;cnt[i].second -= 2;seted[0] = 1;}
            if (!seted[2]){corr[2] = cnt[i].first;cnt[i].second -= 2;seted[2] = 1;}
        }else{
            if (seted[0] && !seted[2]){
                corr[2] = cnt[i].first;
                cnt[i].second -= 2;
                seted[2] = 1;
            }else if (!seted[0]){
                corr[0] = cnt[i].first;
                cnt[i].second -= 2;
                seted[0] = 1;
            }
        }
    }
    for (int i=cnt.size()-1;i>=0;i--){
        // cout << cnt[i].first << " " << cnt[i].second << endl;
        if (cnt[i].second >= 4 && (!seted[1] && !seted[3])){
            if (!seted[3]){corr[3] = cnt[i].first;cnt[i].second -= 2;seted[3] = 1;}
            if (!seted[1]){corr[1] = cnt[i].first;cnt[i].second -= 2;seted[1] = 1;}
        }else if (cnt[i].second >= 2){
            if (seted[3] && !seted[1]){
                corr[1] = cnt[i].first;
                cnt[i].second -= 2;
                seted[1] = 1;
            }else if (!seted[3]){
                corr[3] = cnt[i].first;
                cnt[i].second -= 2;
                seted[3] = 1;
            }
        }
    }

    // for (auto ele: cnt){
    //     cout << ele.first << " 1 " << ele.second << endl;
    //     for (int i=0;i<4;i++){
    //         if (ele.first < 2){
    //             break;
    //         }
    //         if (!seted[i]){
    //             cout << "HER" << endl;
    //             corr[i] = ele.second;
    //             seted[i] = 1;
    //             ele.first -= 2;
    //         }else if (i&1){
    //             if (ele.first >= 2){
    //                 if (ele.second > corr[i]){
    //                     corr[i] = ele.second;
    //                     ele.first -= 2;
    //                 }
    //             }
    //         }else{
    //             if (ele.first >= 2){
    //                 if (ele.second < corr[i]){
    //                     corr[i] = ele.second;
    //                     ele.first -= 2;
    //                 }
    //             }
    //         }
    //     }
    //     cout << ele.first << " 2 " << ele.second << endl;cout << endl;

    // }
    // for (auto ele: seted){
    //     cout << ele << " ";
    // }cout << endl;
    if (find(all(seted), 0) != seted.end()){
        cout << "NO" << endl;return;
    }
    cout << "YES" << endl;
    cout << corr[0] << " " << corr[2] << " " << corr[1] << " " << corr[2] << " " << corr[0] << " " << corr[3] << " " << corr[1] << " " << corr[3] << endl;

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