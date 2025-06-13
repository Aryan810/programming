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

    int n, q;
    cin >> n >> q;
    vector<int> nestpos(n);
    vector<int> pegpos(n);
    vector<int> nestatpos(n);
    rep(i, n){
        nestpos[i] = i;
        pegpos[i] = i;
        nestatpos[i] = i;
    }

    for (int i=0;i<q;i++){
        int typ;cin >> typ;
        if (typ == 1){
            int a, b;
            cin >> a >> b;
            pegpos[a-1] = nestpos[b-1];
        }else if (typ == 2){
            int a, b;cin >> a >> b;
            int temp = nestpos[a-1];
            nestpos[a-1] = nestpos[b-1];
            nestatpos[temp] = b-1;
            nestatpos[nestpos[b-1]] = a-1;
            nestpos[b-1] = temp;
        }else{
            int a;cin >> a;
            cout << nestatpos[pegpos[a-1]]+1 << endl;
        }
    }






}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        solve();

    return 0;
}