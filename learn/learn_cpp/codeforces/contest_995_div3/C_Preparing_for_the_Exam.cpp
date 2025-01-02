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
    int n, m, k;
    cin >> n >> m >> k;
    set<int> s;
    for (int i=1;i<=n;i++) s.insert(i);
    vector<int> v(m);
    rep(i, m){cin >> v[i];}
    for (int i=0;i<k;i++){
        int x;
        cin >> x;
        s.erase(x);
    }
    if (k == n){
        for (int i=0;i<m;i++){
            cout << "1";
        }cout << endl;
    }else if (k == n-1){
        int x = *(s.begin());
        for (int i=0;i<m;i++){
            if (v[i] == x){
                cout << "1";
            }else{
                cout << "0";
            }
        }cout << endl;
    }else{
        for (int i=0;i<m;i++){
            cout << "0";
        }cout << endl;
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