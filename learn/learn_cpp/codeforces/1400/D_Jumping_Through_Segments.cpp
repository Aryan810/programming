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

bool check(int k, vector<pair<int, int> > & levels){
    int low = 0;
    int high = k;
    for (int i=0;i<levels.size();i++){
        auto l = levels[i];
        low = max(low, l.first) - k;
        high = min(high, l.second) + k;
        if (low+k > high-k){
            return 0;
        }
    }
    return 1;
}

void solve(){
    int n;
    cin >> n;
    vector< pair<int, int> > levels(n);
    for (int i=0;i<n;i++){
        cin >> levels[i].first >> levels[i].second;
    }

    int low = -1;
    int high = 1e9;

    while (high - low > 1){
        int mid = (high+low)/2;
        if (check(mid, levels)){
            high = mid;
        }else{
            low = mid + 1;
        }
    }

    if (check(low, levels)){
        cout << low << endl;
    }else{
        cout << high << endl;
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