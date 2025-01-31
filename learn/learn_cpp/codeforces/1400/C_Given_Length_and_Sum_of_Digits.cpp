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

    int m, s;
    cin >> m >> s;
    if (s > 9*m){
        cout << -1 << " " << -1 << endl;
        return;
    }
    if (m == 1 && s == 0){
        cout << 0 << " " << 0 << endl;
        return;
    }
    if (m > 1 && s == 0){
        cout << -1 << " " << -1 << endl;
        return;
    }
    string a = "";
    string b = "";
    
    // for max;
    int x = s;
    for (int i=0;i<m;i++){
        if (x >= 9){
            a.push_back('9');
            x -= 9;
        }else if (x < 9 && x > 0){
            a.push_back(x + '0');
            x = 0;
        }else{
            a.push_back('0');
        }
    }

    // for min;
    x = s;
    int i=0;
    for (;i<m;i++){
        if (x > 9){
            b.push_back('9');
            x -= 9;
        }else{
            break;
        }
    }
    if (x > 0){
         if (i == m-1){
        b.push_back(x + '0');
    }else{
        b.push_back(x-1 + '0');
        for (int j = i+1;j<m-1;j++){
            b.push_back('0');
        }
        b.push_back('1');
    }
    }
    reverse(all(b));
    cout << b << " " << a << endl;
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;

    while(test--){
        solve();
    }

    return 0;
}