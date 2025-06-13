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
    string s;
    cin >> s;

    vi a(n);
    rep(i, n) cin >> a[i];

    vector<pair<int, int> > v;

    for (int i=0;i<n;i++){
        v.push_back({a[i], i});
    }
    sort(rall(v));

    ordered_set<int> os;
    int ans = 1e18;
    int reqk = 0;
    set<int> stops;
    stops.insert(-1);
    stops.insert(n);
    os.insert(-1);
    os.insert(n);

    for (int i=0;i<n;i++){
        auto curr = v[i];
        if (s[curr.second] == 'B'){
            auto right = *stops.upper_bound(curr.second);
            auto left = *(--stops.upper_bound(curr.second));
            int bet = os.order_of_key(right)-os.order_of_key(left)-1;
            if (bet == 0){
                os.insert(curr.second);
                reqk += 1;
                ans = min(ans, curr.first);
                if (reqk > k){
                    break;
                }
            }else{
                os.insert(curr.second);
                ans = min(ans, curr.first);
            }
        }else{
            auto right = *stops.upper_bound(curr.second);
            auto left = *(--stops.upper_bound(curr.second));
            stops.insert(curr.second);
            os.insert(curr.second);
            int er = os.order_of_key(right)-os.order_of_key(curr.second) - 1;
            int el = os.order_of_key(curr.second)-os.order_of_key(left) - 1;
            if (er > 0 && el > 0){
                reqk += 1;
                ans = min(ans, curr.first);
                if (reqk > k){
                    break;
                }
            }else{
                ans = min(ans, curr.first);
            }
        }
        if (i == n-1){
            ans = 0;
        }
    }
    cout << ans << endl;



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