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

    int n, k;
    cin >> n >> k;
    vi a(n);
    map<int, int> num;
    rep(i, n){
        int x;
        cin >> x;
        num[x] += 1;
        a[i] = x;
    }
    vector<pair<int, int> > occur;
    for (auto ele: num){
        occur.push_back({ele.first, ele.second});
    }
    sort(rall(occur), [](pair<int, int> a, pair<int, int> b){
        if (a.second == b.second){
            return a.first < b.first;
        }else{
            return a.second < b.second;
        }
    });
    vector<vector<int> > colorgot(n+1);
    int i = 0;
    while (i < occur.size() && occur[i].second >= k){
        for (int j=0;j<k;j++){
            colorgot[occur[i].first].push_back(j+1);
            occur[i].second -= 1;
        }
        for (int j=0;j<occur[i].second;j++){
            colorgot[occur[i].first].push_back(0);
        }
        i++;
    }
    // cout << occur.size() << endl;
    // for (auto ele: occur){
    //     cout << ele.first << " " << ele.second << endl;
    // }
    while (i < occur.size() && occur[i].second > 0){
        vector<pair<int, int> > assign;
        bool topush = 1;
        for (int j=1;j<=k&&i<occur.size();j++){
            assign.push_back({occur[i].first, j});
            occur[i].second -= 1;
            // cout << i << " " << assign.size() << " " << j <<  endl;
            if (occur[i].second == 0 && j != k){
                if (i == occur.size()-1){
                    for (auto ele: assign){
                        colorgot[ele.first].push_back(0);
                    }
                    topush = 0;
                    break;
                }else{
                    i++;
                }
            }else if (occur[i].second == 0 && j == k){
                i++;
            }
        }
        if (topush){
            for (auto ele: assign){
                colorgot[ele.first].push_back(ele.second);
            }
        }
    }
    i = 0;
    for (i=0;i<n;i++){
        cout << colorgot[a[i]].back() << " ";
        colorgot[a[i]].pop_back();
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