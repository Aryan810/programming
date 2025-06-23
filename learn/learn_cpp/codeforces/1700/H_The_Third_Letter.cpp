// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>
const int M = 1e9 + 7;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

class dsu{
    public:
        int n;
        vector<int> parent, set_size, pos;
        dsu(int n){
            this->n = n;
            parent.resize(n);
            set_size.resize(n);
            pos.resize(n);
            pos.assign(n, 0);
            for (int i = 0; i < n; i++){
                parent[i] = i;
                set_size[i] = 1;
                pos[i] = 0;
            }
        }
        int find(int v){
            if(v == parent[v]) return v;
            return find(parent [v]);
        }
        int findpos(int v){
            if (v == find(v)){
                return 0;
            }
            return pos[v] + findpos(parent[v]);
        }
        void set_union (int p, int q, int dist){
            int dp = findpos(p);
            int dq = findpos(q);
            int a = find(p);
            int b = find(q);
            if(a != b){
                if(set_size[a] < set_size [b]){
                    swap (a, b);
                    swap(dp, dq);
                    dist *= -1;
                }
                // adding b(becoming child) into A(becoming parent)
                pos[b] = dist + dp - dq;
                parent[b] = a;
                set_size[a] += set_size[b];
            }   
        }
};

void solve(){
    
    int n, m;
    cin >> n >> m;
    dsu ds(n);
    vector<array<int, 3> > qu(m);
    bool valid = 1;
    for (int i=0;i<m;i++){
        int a, b, d;
        cin >> b >> a >> d;
        qu[i] = {a, b, d};
        if (ds.find(a-1) == ds.find(b-1)){
            if (ds.findpos(b-1) - ds.findpos(a-1) != d){
                // cout << a << " " << b << endl;
                // cout << ds.find(a-1) << " " << ds.find(b-1) << endl;
                // cout << (ds.findpos(a-1)) << " " << (ds.findpos(b-1)) << endl;
                valid = 0;
            }
        }else{
            // cout << a << " + " << b << endl;
            ds.set_union(a-1, b-1, d);
        }
    }
    // cout << ds.findpos(1) << endl;
    if (valid){cout << "YES" << endl;}else{
        cout << "NO" << endl;
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}