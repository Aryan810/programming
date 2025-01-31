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

    int n, m;
    cin >> n >> m;
    vector<pair<vector<int>, int> > grid(n);
    for (int i=0;i<n;i++){
        vector<int> cards(m);
        rep(j, m){
            cin >> cards[j];
        }
        sort(all(cards));
        grid[i] = {cards, i};
    }

    sort(all(grid), [](pair<vector<int> , int> a, pair<vector<int>, int> b){
        return (a.first[0] < b.first[0]);
    });
    int last = -1;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (grid[j].first[i] > last){
                last = grid[j].first[i];
            }else{
                cout << -1 << endl;return;
            }
        }
    }
    for (int i=0;i<n;i++){
        cout << grid[i].second + 1 << " ";
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