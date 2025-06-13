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

void dooper(int j, int i, vector<int> & a){
    int x = a[i];
    int y = a[j];
    a[j] = x+1;
    a[i] = y-1;
}

void solve(){

    int n;
    cin >> n;

    vi a(n);
    rep(i, n) cin >> a[i];

    vi b(n);
    rep(i, n) cin >> b[i];
    
    int sa = accumulate(all(a), 0ll);
    int sb = accumulate(all(b), 0ll);

    if (sa != sb){
        cout << "No" << endl;return;
    }
    vector<pair<int, int> > oper;
    if (n == 2){
        if (a == b){
            cout << "Yes" << endl;
            cout << 0 << endl;
        }else{
            dooper(1, 0, a);
            if (a == b){
                cout << "Yes" << endl;
                cout << 1 << endl;
                cout << "1 2" << endl;
            }else{
                cout << "No" << endl;
            }
        }
        return;
    }
    for (int i=0;i<=(n-3);i++){
        while (a[i] != b[i]){
            if (a[i] > b[i]){
                dooper(i+2, i, a);
                oper.push_back({i+2, i});
                dooper(i+2, i+1, a);
                oper.push_back({i+2, i+1});
                dooper(i+1, i, a);
                oper.push_back({i+1, i});
            }else{
                dooper(i+1, i, a);
                oper.push_back({i+1, i});
                dooper(i+2, i+1, a);
                oper.push_back({i+2, i+1});
                dooper(i+2, i, a);
                oper.push_back({i+2, i});
            }
        }
    }
    
  
    while (a[n-1] != b[n-1]){
        if (a[n-1] > b[n-1]){
            // oper
            dooper(n-1, n-2, a);
            oper.push_back({n-1, n-2});
            
            // swap
            dooper(n-1, n-3, a);
            oper.push_back({n-1, n-3});
            dooper(n-2, n-3, a);
            oper.push_back({n-2, n-3});
            dooper(n-1, n-3, a);
            oper.push_back({n-1, n-3});
        }else{
            // swap
            dooper(n-1, n-3, a);
            oper.push_back({n-1, n-3});
            dooper(n-2, n-3, a);
            oper.push_back({n-2, n-3});
            dooper(n-1, n-3, a);
            oper.push_back({n-1, n-3});

            // oper
            dooper(n-1, n-2, a);
            oper.push_back({n-1, n-2});
        }
    }
    
    cout << "Yes" << endl;
    cout << oper.size() << endl;
    for (auto ele: oper){
        cout << ele.second + 1 << " " << ele.first + 1 << endl;
    }
        
    
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        solve();

    return 0;
}