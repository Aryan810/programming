// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define each(x, a) for (auto &x : a)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pi pair<int, int>
#define p(a, b) pair<a, b>
#define vi vector<int>
#define vii vector<int>::iterator
#define vvi vector<vector<int> >
#define vv(x) vector<vector<x> >
#define PRECISION(x) cout << fixed << setprecision(x);
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define umap(x, y) unordered_map<x, y, custom_hash>
const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
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
    struct dsu ds(n+1);

    map<int, set<int> > mp;

    for (int i=2;i<=n;i++){
        if (ds.find(i) == i){
            mp[i].insert(i);
            for (int j=2*i;j<=n;j+=i){
                if (ds.find(j) == j){
                    ds.set_union(i, j);
                    mp[i].insert(j);
                }else{
                    int par = ds.find(j);
                    mp[par].erase(j);
                    mp[i].insert(j);
                    ds.parent[j] = j;
                    ds.set_size[par] -= 1;
                    ds.set_union(i, j);
                }
            }
        }
    }
    // for (auto & ele: mp){
    //     cout << ele.first << endl;
    //     for (auto & e: ele.second){
    //         cout << e << " ";
    //     }cout << endl;
    // }
    vector<int> out(n+1);
    for (auto & ele: mp){
        auto & st = ele.second;
        if (st.size() == 0){
            continue;
        }else if (st.size() == 1){
            out[*st.begin()] = *st.begin();
            continue;
        }
        auto it1 = st.begin();
        auto it2 = ++st.begin();
        while (1){
            out[*it1] = *it2;
            if (it2 == st.end()){
                break;
            }
            it1++;
            it2++;
        }

        out[*(--st.end())] = *st.begin();
    }
    out[1] = 1;
    for (int i=1;i<=n;i++){
        cout << out[i] << " ";
    }cout << endl;

    

}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}