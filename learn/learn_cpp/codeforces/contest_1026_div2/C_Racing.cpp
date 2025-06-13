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

void solve(){

    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    vector<pair<int, int> > her(n);
    rep(i, n) cin >> her[i].first >> her[i].second;
    vector<int> deq;
    int h = 0;
    int num = 1;
    for (int i=0;i<n;i++){
        if (a[i] == 1){
            h += 1;
        }else if (a[i] == -1){
            num += 1;
        }
        int b = h;
        int t = h + num - 1;
        // cout << b << " " << t << endl;
        // cout << her[i].first << " - " << her[i].second << endl;
        if (her[i].first > b && her[i].second >= t){
            if (her[i].first-b >= num){
                cout << -1 << endl;return;
            }
            for (int k=0;k<(her[i].first-b);k++){
                deq.push_back(1);
            }
            num -= (her[i].first-b);
            h = her[i].first;
        }else if (her[i].first <= b && her[i].second < t){
            if (t-her[i].second >= num){
                cout << -1 << endl;return;
            }
            for (int k=0;k<(t-her[i].second);k++){
                deq.push_back(0);
            }
            num -= (t-her[i].second);
        }else if (her[i].first > b && her[i].second < t){
            if ((t-her[i].second + her[i].first-b) >= num){
                cout << -1 << endl;return;
            }
            for (int k=0;k<(her[i].first-b);k++){
                deq.push_back(1);
            }
            for (int k=0;k<(t-her[i].second);k++){
                deq.push_back(0);
            }
            num -= (her[i].first-b)+(t-her[i].second);
            h = her[i].first;
        }
    }
    // cout << deq.size() << endl;
    int j = 0;
    for (int i=0;i<n;i++){
        if (a[i] == -1){
            if (j < deq.size()){a[i] = deq[j];j+=1;}else{
                a[i] = 0;
            }
        }
    }
    for (auto ele: a){
        cout << ele << " ";
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