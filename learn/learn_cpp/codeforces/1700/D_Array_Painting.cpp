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

    int i = 0;
    int j = 0;
    vector<pair<int, int> > dta;
    while (i < n && j < n){
        while (i < n && a[i] == 0){
            i += 1;
        }
        j = i;

        int foundTwo = 0;
        while (1){
            if (a[j] == 2){
                foundTwo = 1;
            }
            if (j+1 == n || a[j+1] == 0){
                break;
            }
            j += 1;
        }

        if (foundTwo){
            dta.push_back({i-1, j+1});
            j += 2;
        }else{
            if (dta.size() == 0){
                if (i == 0){
                    dta.push_back({i, j+1});
                    j += 2;
                }else{
                    dta.push_back({i-1, j});
                    j += 1;
                }
                
            }else{
                auto last = dta.back();
                if (last.second >= i-1){
                    dta.push_back({i, j+1});
                    j += 2;
                }else{
                    dta.push_back({i-1, j});
                    j += 1;
                }
            }
            
        }

        i = j;
    }
    int ans = 0;
    int l = 0;
    for (int i=0;i<dta.size();i++){
        // cout << dta[i].first << " " << dta[xi].second << endl;
        if (dta[i].first > l){
            ans += dta[i].first - l;
        }
        l = dta[i].second + 1;
    }

    if (l < n-1){
        ans += n-1-l;
    }
    cout << ans+dta.size() << endl;


}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;

    while(test--){
        solve();
    }

    return 0;
}