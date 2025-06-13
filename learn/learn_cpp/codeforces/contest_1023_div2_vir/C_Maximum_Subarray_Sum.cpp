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
    int one = accumulate(all(s), -1*s.size()*'0');
    vi a(n);
    rep(i, n) cin >> a[i];

    vector<int> maxes;
    multiset<int> st;
    int sm = 0;
    int ans = -1e13;
    for (int i=0;i<n;i++){
        // cout << ans << " " << sm << endl;
        // cout << a[i] << endl;
        if (s[i] == '0'){
            sm = 0;
            maxes.push_back(ans);
            st.clear();
            ans = -1e13;
        }else{
            sm += a[i];
            if (st.size() == 0){
                ans = max(ans, sm);
            }else{
                ans = max(ans, sm - min(*st.begin(), 0ll));
            }
            st.insert(sm);
        }
    }
    maxes.push_back(ans);

    for (auto ele: maxes){
        if (ele > k){
            cout << "No" << endl;return;
        }
    }
    for (auto ele: maxes){
        if (ele == k){
            cout << "Yes" << endl;
            for (int i=0;i<n;i++){
                if (s[i] == '1'){
                    cout << a[i] << " ";
                }else{
                    cout << -1*(int)(1e13) << " ";
                }
            }cout << endl;
            return;
        }
    }
    int f = -1;
    for (int i=0;i<n;i++){
        if (s[i] == '0'){
            if (f == -1){f = i;}else{
                a[i] = -1*(1e13);
            }
        }
    }
    if (f == -1){
        cout << "No" << endl;return;
    }
    int right = 0;
    int left = 0;
    int sr = 0;
    for (int i=f+1;i<n;i++){
        sr += a[i];
        if (right < sr){
            right = sr;
        }
    }

    int sl = 0;
    for (int i=f-1;i>=0;i--){
        sl += a[i];
        if (left < sl){
            left = sl;
        }
    }

    cout << "Yes" << endl;
    for (int i=0;i<n;i++){
        if (i == f){
            cout << (k - right - left) << " ";
        }else{
            cout << a[i] << " ";
        }
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