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

// DSU
const int N = 1e5+10;
int parent[N];
int sz[N];

void make(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find(int v){
    if (v == parent[v]){return v;}
    return parent[v] = find(parent[v]);
}

void Union(int i, int j){
    int p = find(i);
    int q = find(j);
    if (p != q){
        if (sz[p] > sz[q]){
            parent[q] = p;
            sz[p] += sz[q];
        }else{
            parent[p] = q;
            sz[q] += sz[p];
        }
    }
}

void solve(){

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<vector<set<int> > > qri(3, vector<set<int> >(3));

    for (int i=0;i<q;i++){
        string s1, s2;
        cin >> s1 >> s2;
        int a = s1[0]-'a';
        int b = s2[0]-'a';
        qri[a][b].insert(i);
    }

    for (int i=0;i<s.size();i++){
        if (s[i] == 'a'){continue;}
        if (s[i] == 'b'){
            if (qri[1][0].size() > 0){
                auto it = qri[1][0].begin();
                s[i] = 'a';
                qri[1][0].erase(it);
            }else if (qri[1][2].size() > 0 && qri[2][0].upper_bound(*qri[1][2].begin()) != qri[2][0].end()){
                auto it1 = qri[1][2].begin();
                auto it2 = qri[2][0].upper_bound(*it1);
                s[i] = 'a';
                qri[1][2].erase(it1);
                qri[2][0].erase(it2);
            }
        }else{
            if (qri[2][0].size() > 0){
                s[i] = 'a';
                qri[2][0].erase(qri[2][0].begin());
            }else if (qri[2][1].size() > 0 && qri[1][0].upper_bound(*qri[2][1].begin()) != qri[1][0].end()){
                s[i] = 'a';
                auto it1 = qri[2][1].begin();
                auto it2 = qri[1][0].upper_bound(*it1);
                qri[2][1].erase(it1);
                qri[1][0].erase(it2);
            }else if (qri[2][1].size() > 0){
                s[i] = 'b';
                qri[2][1].erase(qri[2][1].begin());
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