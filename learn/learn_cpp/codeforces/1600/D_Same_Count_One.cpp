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

bool comp(pair<vector<int>, int> & a, pair<vector<int>, int> & b){
    int s1 = accumulate(all(a.first), 0ll);
    int s2 = accumulate(all(b.first), 0ll);
    return s1 < s2;
}

void solve(){

    int n, m;
    cin >> n >> m;

    vector<vector<int> > grid(n, vector<int>(m, 0));
    int sm = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int x;
            cin >> x;
            sm += x;
            grid[i][j] = x;
        }
    }
    if (sm%n != 0){
        cout << -1 << endl;return;
    }
    vector< pair<vector<int>, int> > dta;

    for (int i=0;i<n;i++){
        vector<int> temp;
        int temp1 = 0;
        for (int j=0;j<m;j++){
            int x = grid[i][j];
            temp1 += x;
            temp.push_back(x);
        }
        if (temp1 != sm/n){
            dta.push_back({temp, i});
        }
    }
    sort(all(dta), comp);
    // for (auto ele: dta){
    //     for (auto e: ele.first){
    //         cout << e << " ";
    //     }cout << endl;
    // }cout << endl;
    int i = 0;
    int j = dta.size()-1;
    vector<array<int, 3> > out;
    while (i < j){
        int s = accumulate(all(dta[i].first), 0ll);
        int l = accumulate(all(dta[j].first), 0ll);
        if (l != sm/n && s != sm/n){
            for (int k=0;k<m;k++){
                if (s < l){
                    if (dta[j].first[k] > dta[i].first[k]){
                        swap(dta[j].first[k], dta[i].first[k]);
                        s += 1;
                        l -= 1;
                        out.push_back({dta[i].second+1, dta[j].second+1, k+1});
                    }
                }else if (s > l){
                    if (dta[i].first[k] > dta[j].first[k]){
                        swap(dta[j].first[k], dta[i].first[k]);
                        s -= 1;
                        l += 1;
                        out.push_back({dta[i].second+1, dta[j].second+1, k+1});
                    }
                }
                if (s == sm/n && l == sm/n){
                    i += 1;
                    j -= 1;
                    break;
                }else if (s == sm/n){
                    i += 1;
                    break;
                }else if (l == sm/n){
                    j -= 1;
                    break;
                }
            }
        }
    }

    cout << out.size() << endl;
    for (auto ele: out){
        cout << ele[0] << " " << ele[1] << " " << ele[2] << endl;
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