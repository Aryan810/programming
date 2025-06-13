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

    int n, x;
    cin >> n >> x;
    vi p(n);
    int xpos = -1;
    rep(i, n){
        int y;
        cin >> y;
        if (x == y){
            xpos = i+1;
        }
        p[i] = y;
    }

    int l = 1;
    int h = n+1;
    vector<int> vals;
    while (h-l > 1){
        int mid = (l + h) / 2;
        vals.push_back(mid);
        if (p[mid-1] <= x){
            l = mid;
        }else{
            h = mid;
        }
    }


    set<int> s;
    bool found = 0;
    for (int i=0;i<vals.size();i++){
        s.insert(p[vals[i]]);
        if (p[vals[i]-1] == x){
            found = 1;
        }
    }
    // for (auto ele: vals){
    //     cout << ele << " ";
    // }cout << endl;
    if (xpos == l){
        cout << 0 << endl;return;
    }
    if (found){
        cout << 2 << endl;
        int ind = -1;
        for (int i=1;i<=n;i++){
            if (p[i-1] < x){
                ind = i;
                cout << i << " " << xpos << endl;
                break;
            }
        }
        cout << ind << " " << l << endl;
    }else{
        cout << 1 << endl;
        cout << xpos << " " << l << endl;
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