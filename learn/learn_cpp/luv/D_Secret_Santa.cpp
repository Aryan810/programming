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
    rep(i, n) cin >> a[i];

    vi b(n, -1);
    set<int> done;
    set<int> left;
    for (int i=1;i<=n;i++){
        left.insert(i);
    }
    int ans = 0;
    for (int i=0;i<n;i++){
        int x = a[i];
        if (done.find(x) == done.end()){
            done.insert(x);
            left.erase(x);
            b[i] = x;
            ans += 1;
        }
    }
    if (left.size() == 1){
        int f = *left.begin();
        for (int i=0;i<n;i++){
            if (b[i] == -1){
                if (i+1 == f){
                    int req = a[i];
                    for (int j=0;j<n;j++){
                        if (b[j] == req){
                            b[j] = f;
                            b[i] = req;
                            break;
                        }
                    }
                    break;
                }else{
                    b[i] = f;
                    break;
                }
            }
        }
    }else{
        vector<int> lft;
        for (int i=0;i<n;i++){
            if (b[i] == -1){
                if (left.find(i+1) != left.end()){
                    lft.push_back(i+1);
                    left.erase(i+1);
                    b[i] = -2;
                }

            }
        }
        // for (auto ele: left){
        //     cout << ele << " ";
        // }cout << endl;
        // if (left.size() > 0){
        if (lft.size() == 1){
            b[lft[0]-1] = *left.begin();
            left.erase(left.begin());
            left.insert(lft[0]);
            lft.pop_back();
        }
        for (int i=0;i<n;i++){
            if (left.size() == 0){
                break;
            }
            if (b[i] == -1){
                // cout << "ERHE" << endl;
                b[i] = *left.begin();
                left.erase(left.begin());
                // cout << "TJERE" << endl;
            }
            // }
        }
        if (lft.size() > 0){
            int curr = 1;
            for (int i=0;i<n;i++){
                if (b[i] == -2){
                    b[i] = lft[curr];
                    curr = (curr + 1)%(lft.size());
                }
            }
        }
    }
    cout << ans << endl;
    for (auto ele: b){
        cout << ele << " ";
    }cout << endl;

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