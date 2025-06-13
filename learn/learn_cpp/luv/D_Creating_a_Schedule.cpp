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

// DSU
const int N = 1e5+10;
int parent[N];
int sz[N];

void make(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find(int v){
    if (v == parent[v]){return v;}
    return parent[v] = find(parent[v]);
}

void Union(int i, int j){
    int p = find(i);
    int q = find(j);
    if (p != q){
        if (sz[p] > sz[q]){
            parent[q] = p;
            sz[p] += sz[q];
        }else{
            parent[p] = q;
            sz[q] += sz[p];
        }
    }
}

void solve(){

    int n, m;
    cin >> n >> m;

    vi a(m);
    map<int, vector<int> > num;
    rep(i, m) cin >> a[i];

    for (int i=0;i<m;i++){
        int flor = a[i]/100;
        num[flor].push_back(a[i]);
    }
    // for (auto ele: num){
    //     cout << ele.first << endl;
    //     for (auto e: ele.second){
    //         cout << e << " ";
    //     }cout << endl;
    // }
    auto f = num.begin();
    auto l = --num.end();
    // cout << "here" << endl;
    vector<array<int, 6> > dta(n+1);
    int leftGrp = n;
    while (leftGrp > 0){
        // cout << "here" << endl;
        // cout << f->first << " " << f->second.size() << " --- " << l->first << " " << l->second.size() << endl;
        if (f->second.size() == 0){
            f++;
        }
        if (l->second.size() == 0){
            l--;
        }
        if (leftGrp != 1){
            array<int, 6> arr;
            int g1 = f->second.back();
            f->second.pop_back();
            int g2 = l->second.back();
            l->second.pop_back();
            bool flag = 1;
            for (int i=0;i<6;i++){
                if (flag){
                    dta[leftGrp][i] = g1;
                    flag = 1 - flag;
                }else{
                    dta[leftGrp][i] = g2;
                    flag = 1 - flag;
                }
            }
            flag = 0;
            for (int i=0;i<6;i++){
                if (flag){
                    dta[leftGrp-1][i] = g1;
                    flag = 1 - flag;
                }else{
                    dta[leftGrp-1][i] = g2;
                    flag = 1 - flag;

                }
            }
            leftGrp -= 2;
        }else{
            if (f == l){
                for (int i=0;i<6;i++){
                    dta[leftGrp][i] = f->second.back();
                }
            }else{
                int g1 = f->second.back();
                f->second.pop_back();
                int g2 = l->second.back();
                l->second.pop_back();
                bool flag = 1;
                for (int i=0;i<6;i++){
                    if (flag){
                        dta[leftGrp][i] = g1;
                        flag = 1 - flag;

                    }else{
                        dta[leftGrp][i] = g2;
                        flag = 1 - flag;

                    }
                }
            }
            leftGrp -= 1;
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=0;j<6;j++){
            cout << dta[i][j] << " ";
        }cout << endl;
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