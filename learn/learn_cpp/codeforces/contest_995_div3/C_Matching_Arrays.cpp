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
    int n, x;
    cin >> n >> x;

    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    auto c = a;
    rep(i, n) cin >> b[i];
    sort(all(c));
    sort(rall(b));
    
    map<int, vector<int> > m;

    for (int i=n-x;i<n;i++){
        if (c[i] > b.back()){
            m[c[i]].push_back(b.back());
            b.pop_back();
        }else{
            cout << "NO" << endl;
            return;
        }
    }
    reverse(all(b));
    for (int i=n-x-1;i>=0;i--){
        if (c[i] <= b.back()){
            m[c[i]].push_back(b.back());
            b.pop_back();
        }else{
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (int i=0;i<n;i++){
        cout << m[a[i]].back() <<  " ";
        m[a[i]].pop_back();
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