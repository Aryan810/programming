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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){

    int n, s1, s2;cin >> n >> s1 >> s2;
    vector<pair<int, int> > v;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back({i, x});
    }
    sort(all(v), [](pair<int, int> a, pair<int, int> b){
        return (a.second > b.second);
    });
    vector<int> sv1, sv2;
    for (int i=0;i<v.size();i++){
        int cost1 = v[i].second * (s1 * (sv1.size() + 1));
        int cost2 = v[i].second * (s2 * (sv2.size() + 1));
        if (cost1 == cost2){
            if (s1 < s2){
                sv1.push_back(v[i].first + 1);
            }else{
                sv2.push_back(v[i].first + 1);
            }
        }else if (cost1 > cost2){
            sv2.push_back(v[i].first + 1);
        }else{
            sv1.push_back(v[i].first + 1);
        }
    }
    cout << sv1.size() << " ";
    for(auto ele: sv1){
        cout << ele << " ";
    }cout << endl;
    cout << sv2.size() << " ";
    for (auto ele: sv2){
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