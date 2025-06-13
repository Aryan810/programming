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

    int n, k;
    cin >> n >> k;

    string s;cin >> s;

    vi l(k), r(k);
    rep(i, k) cin >> l[i];
    rep(i, k) cin >> r[i];

    int q;
    cin >> q;
    
    set<int> m;
    map<int, int> num;
    rep(i, q){
        int x;
        cin >> x;
        num[x] += 1;
        m.insert(x);
    }
    vector<int> mods;

    for (auto ele: m){
        if (num[ele]&1){mods.push_back(ele-1);}
    }
    for (int i=0;i<k;i++){
        int f = l[i]-1;
        int s1 = r[i]-1;
        for (int j=f;j<=s1;j++){
            if (j <= (f+s1)/2){
                auto it1 = upper_bound(all(mods), j);
                auto it2 = lower_bound(all(mods), f);
                int x = (int)(it1-it2);
                if (x&1){
                    swap(s[j], s[f+s1-j]);
                }
            }else{
                auto it1 = lower_bound(all(mods), j);
                auto it2 = upper_bound(all(mods), s1)-1;
                int x = (int)(it2-it1+1);
                if (x&1){
                    swap(s[j], s[f+s1-j]);
                }
            }
        }
    }
    cout << s << endl;

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