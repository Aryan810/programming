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

    string st;cin >> st;


    for (int sz=st.size()/2+1;sz<st.size();sz++){
        int f = 0;
        int s = sz-1;
        int l = st.size()-1;
        bool ok = 1;
        for (int i=0;i<sz;i++){
            if (st[l] != st[s]){
                ok = 0;
                break;
            }
            s -= 1;
            l -= 1;
        }
        if (!ok){
            continue;
        }

        cout << "YES" << endl;
        for (int i=0;i<sz;i++){
            cout << st[f];
            f += 1;
        }cout << endl;
        return;
    }

    // for(int sz=1;sz <= st.size()/3;sz++){
    //     int rem = st.size()-3*sz;
    //     if (rem&1){continue;}
    //     rem /= 2;
    //     int f = 0;
    //     int s = sz+rem;
    //     int t = s + sz + rem;
    //     bool ok = 1;
    //     for (int i=0;i<sz;i++){
    //         if (!(st[f] == st[s] && st[s] == st[t])){
    //             ok = 0;
    //             break;
    //         }
            
    //         f += 1;
    //         s += 1;
    //         t += 1;
    //     }

    //     if (!ok){
    //         continue;
    //     }
    //     ok = 1;
    //     f = sz;
    //     s = f + sz + rem;
    //     for (int i=0;i<rem;i++){
    //         if (!(st[f] == st[s])){
    //             ok = 0;
    //             break;
    //         }

    //         f += 1;
    //         s += 1;
    //     }
    //     if (!ok){
    //         continue;
    //     }
    //     string temp(2*sz + rem, '.');
    //     f = 0;
    //     s = sz+rem;
    //     for (int i=0;i<sz;i++){
    //         temp[f] = st[f];
    //         temp[s] = temp[f];
    //         f += 1;
    //         s += 1;
    //     }
    //     f = sz;
    //     for (int i=0;i<rem;i++){
    //         temp[f] = st[f];
    //         f += 1;
    //     }
    //     // found answer.
    //     cout << "YES" << endl;
    //     cout << temp << endl;return;
    // }   

    cout << "NO" << endl;


}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int test;
    // cin >> test;

    // while(test--){
        solve();
    // }

    return 0;
}