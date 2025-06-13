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

void solve(){

    int n;
    cin >> n;

    vi a(n);
    rep(i ,n) cin >> a[i];

    vi b = a;
    sort(all(b));
    vector<pair<int, int> > out;

    vector<set<int> > ind(3);

    for (int i=0;i<n;i++){
        ind[a[i]].insert(i);
    }

    for (int i=0;i<n;i++){
        if (b[i] == 0 && b[i] != a[i]){
            if (a[i] == 1){
                int j = *(--ind[b[i]].end());
                ind[b[i]].erase(j);
                ind[b[i]].insert(i);
                ind[a[i]].erase(i);
                ind[a[i]].insert(j);
                out.push_back({i+1, j+1});
                swap(a[i], a[j]);
            }else{

                // get 1 at this position
                int j = *(--ind[1].end());
                ind[1].erase(j);
                ind[1].insert(i);
                ind[2].erase(i);
                ind[2].insert(j);
                out.push_back({i+1, j+1});
                swap(a[i], a[j]);

                // get 0 at this position
                j = *(--ind[b[i]].end());
                ind[b[i]].erase(j);
                ind[b[i]].insert(i);
                ind[a[i]].erase(i);
                ind[a[i]].insert(j);
                out.push_back({i+1, j+1});
                swap(a[i], a[j]);
            }
        }

        if (b[i] == 1 && b[i] != a[i]){
            // get 1 here
            int j = *(--ind[1].end());
            ind[1].erase(j);
            ind[1].insert(i);
            ind[2].erase(i);
            ind[2].insert(j);
            out.push_back({i+1, j+1});
            swap(a[i], a[j]);
        }
    }
    cout << out.size() << endl;
    for (auto ele: out){
        cout << ele.first << " " << ele.second << endl;
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