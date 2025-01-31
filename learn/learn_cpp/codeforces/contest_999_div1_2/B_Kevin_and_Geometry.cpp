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

    int n;
    cin >> n;
    map<int, int> num;
    rep(i, n){
        int x;
        cin >> x;
        num[x] += 1;
    }
    vector<pair<int, int> > nm;
    for (auto ele: num){
        nm.push_back(ele);
    }
    sort(rall(nm), [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    });
    if (nm[0].second < 2){
        cout << -1 << endl;return;
    }
    if (nm.size() > 1 && (nm[0].second > 1 && nm[1].second > 1)){
        cout << nm[0].first << " " << nm[0].first << " " << nm[1].first << " " << nm[1].first << endl;
    }else if (nm[0].second >= 4){
        cout << nm[0].first << " " << nm[0].first << " " << nm[0].first << " " << nm[0].first << endl;
    }else{
        int sames = nm[0].first;
        vector<int> a;
        for (int i=1;i<nm.size();i++){
            a.push_back(nm[i].first);
        }
        if (nm[0].second > 2){
            a.push_back(nm[0].first);
        }
        sort(all(a));
        int msum = 1e18;
        pair<int, int> temp;
        for (int i=0;i<a.size()-1;i++){
            int x = abs(a[i+1]-a[i]);
            if (msum > x){
                msum = x;
                temp = {a[i], a[i+1]};
            }
        }
        if (msum < 2*sames){
            cout << temp.first << " " << temp.second << " " << sames << " " << sames << endl;
        }else{
            cout << -1 << endl;
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