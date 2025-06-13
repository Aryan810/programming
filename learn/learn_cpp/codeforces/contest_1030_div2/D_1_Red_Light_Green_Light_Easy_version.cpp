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

void solve(){
    
    int n, k;
    cin >> n >> k;

    map<int, int> islight;
    vector<int> p(n);
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        islight[x] = 1;
        p[i] = x;
    }
    map<int, int> wt;
    int lc = 1;
    for (int i=0;i<n;i++){
        int w;
        cin >> w;
        wt[p[i]] = w;
        lc = lcm(lc, w);
    }

    int q;
    cin >> q;
    for (int i=0;i<q;i++){
        int pos;cin >> pos;
        int dir = 1;
        int t = 0;
        bool done = 0;
        int iter = 0;
        map<pair<int, int>, bool> mp;
        while (pos >= 1 && pos <= 1e15){
            if (islight[pos]){
                if ((t - wt[pos])%k == 0){
                    // red
                    if (mp.find({pos, dir}) != mp.end()){
                        break;
                    }
                    mp[{pos, dir}] = 1;
                    dir = 1 - dir;
                    if (dir){
                        pos += 1;
                    }else{
                        pos -= 1;
                    }
                    t += 1;
                }else{
                    if (dir){
                        pos += 1;
                    }else{
                        pos -= 1;
                    }
                    t += 1;
                }
            }else{
                if (dir == 1){
                    auto it = lower_bound(all(p), pos);
                    if (it == p.end()){
                        done = 1;
                        break;
                    }
                    t += (*it) - pos;
                    pos = *it;
                }else{
                    auto it = lower_bound(all(p), pos);
                    if (it == p.begin()){
                        done = 1;
                        break;
                    }
                    it -= 1;
                    // cout << "HERE: " << *it << endl;
                    t += pos - (*it);
                    pos = *it;
                }
            }
            iter += 1;
            if (iter > lc+10000){
                break;
            }
        }
        if (done || (pos < 1 || pos > 1e15)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
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