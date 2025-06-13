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

vector<set<int> > graph;

void solve(){

    int n;
    cin >> n;
    graph.clear();
    graph.resize(n+1);

    for (int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    pair<int, int> temp = {0, 0};
    multiset<int> m;
    for (int i=1;i<=n;i++){
        m.insert(graph[i].size());
        if (graph[i].size() > temp.second){
            temp.second = graph[i].size();
            temp.first = i;
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (graph[i].size() == temp.second){
            // find the one after oper in this which has max edges joined.
            int temp = 1;
            temp += graph[i].size() - 1;
            vector<int> v;
            m.erase(m.find(graph[i].size()));
            for (auto ele: graph[i]){
                int is = graph[ele].size();
                v.push_back(is);
                m.erase(m.find(is));
                m.insert(is-1);
            }
            temp += *(--m.end()) - 1;
            ans = max(ans, temp);
            m.insert(graph[i].size());
            for (auto ele: v){
                m.insert(ele);
                m.erase(m.find(ele-1));
            }
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