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

    string p, s;
    cin >> p >> s;

    vi a, b;
    if (p[0] != s[0]){
        cout << "NO" << endl;return;
    }

    int i=0;
    while (i < p.size()){
        int f = p[i];
        int cp = 0;
        while (i < p.size() && p[i] == f){
            i += 1;
            cp += 1;
        }
        a.push_back(cp);
    }
    i = 0;
    while (i < s.size()){
        int f = s[i];
        int cs = 0;
        while (i < s.size() && s[i] == f){
            i += 1;
            cs += 1;
        }
        b.push_back(cs);
    }
    int j = 0;
    for (int i=0;i<a.size();i++){
        if (!(j < b.size() && (b[j] >= a[i] && b[j] <= 2*a[i]))){
            cout << "NO" << endl;return;
        }
        j += 1;
    }
    if (j < b.size()){
        cout << "NO" << endl;return;
    }

    cout << "YES" << endl;


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