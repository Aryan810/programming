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
        parent.assign(n, -1);
        set_size.resize(n);
    }
    int y = 0;
    void make(int x){
        this->y += 1;
        parent[x] = x;
        set_size[x] = 1;
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
    vi b(n);
    rep(i, n) cin >> b[i];
    vi a;
    int last = -1;
    for (int i=0;i<n;i++){
        if (last == -1){
            last = b[i];
            a.push_back(b[i]);
        }else{
            if (b[i] != last){
                a.push_back(b[i]);
                last = b[i];
            }
        }
    }
    n = a.size();
    // for (auto ele: a){
    //     cout << ele << " ";
    // }cout << endl;
    if (n == 1){
        cout << 1 << endl;return;
    }
    struct dsu ds(n+1);
    set<int> s;
    map<int, int> num;
    map<int, vector<int> > ind;
    for (int i=0;i<n;i++){
        num[a[i]] += 1;
        s.insert(a[i]);
        ind[a[i]].push_back(i);
    }
    vector<int> diff;
    for (auto ele: s){
        diff.push_back(ele);
    }
    while (diff.size() > 0){
        vector<int> & inds = ind[diff.back()];
        diff.pop_back();
        for (auto ele: inds){
            int f = ele + 1;
            int s = ele - 1;
            if (f < n && ds.parent[f] != -1){
                ds.make(ele);
                ds.set_union(ele, f);
            }else if (s >= 0 && ds.parent[s] != -1){
                ds.make(ele);
                ds.set_union(ele, s);
            }else{
                ds.make(ele);
            }
        }
    }
    set<int> diffParent;
    for (auto ele: ds.parent){
        if (ele != -1){
            diffParent.insert(ele);
        }
    }
    cout << diffParent.size() << endl;



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