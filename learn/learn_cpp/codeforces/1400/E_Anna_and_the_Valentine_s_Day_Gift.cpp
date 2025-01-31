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
    int n, m;cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];
    vector<int> zeros;
    int digits = 0;
    for (int i=0;i<n;i++){
        int x = a[i];
        string s = to_string(x);
        int zero = 0;
        while (s.back() == '0'){
            s.pop_back();
            zero += 1;
        }
        digits += s.size();
        zeros.push_back(zero);
    }
    sort(rall(zeros));
    for (int i=1;i<n;i+=2){
        digits += zeros[i];
    }
    if (digits > m){
        cout << "Sasha" << endl;
    }else{
        cout << "Anna" << endl;
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