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

bool isValid(pair<int, int> & f, int n, int m){
    if (!((f.first >= 1 && f.first <= n) && (f.second >= 1 && f.second <= m))){
        return 0;
    }else{
        return 1;
    }
}

void solve(){

    int n, m;
    cin >> n >> m;
    int d, u;
    cout << "? " << n << " " << 1 << endl;cout.flush();
    cin >> d;
    cout << "? " << 1 << " " << m << endl;cout.flush();
    cin >> u;
    
    if (u+d == n-1 && u+d == m-1){
        cout << "! " << u+1 << " " << d+1 << endl;cout.flush();
    }else if (u+d == n-1){
        // cout << "HER" << endl;
        pair<int, int> l = {u+1, d+1};
        if (l.second > m){
            l.second = m;
        }
        int resp;
        cout << "? " << l.first << " " << l.second << endl;cout.flush();
        cin >> resp;
        cout << "! " << l.first << " " << l.second-resp << endl;cout.flush();
    }else if (u+d == m-1){
        // cout << "HER2" << endl;

        pair<int, int> f = {u+1, d+1};
        if (f.first > n){
            f.first = n;
        }
        int resp;
        cout << "? " << f.first << " " << f.second << endl;cout.flush();
        cin >> resp;
        cout << "! " << f.first - resp << " " << f.second << endl;cout.flush();
    }else{
        pair<int, int> f = {n-d, m-u};
        pair<int, int> s = {u+1, d+1};
        if (!isValid(f, n, m)){
            cout << "! " << s.first << " " << s.second << endl;cout.flush();return;
        }else if (!isValid(s, n, m)){
            cout << "! " << f.first << " " << f.second << endl;cout.flush();return;
        }
        int resp;
        cout << "? " << f.first << " " << f.second << endl;cout.flush();
        cin >> resp;
        if (resp == 0){
            cout << "! " << f.first << " " << f.second << endl;cout.flush();
        }else{
            cout << "! " << s.first << " " << s.second << endl;cout.flush();
        }
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