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

    string s;
    cin >> s;
    if (s == "N"){cout << "S" << endl;}
    else if (s == "S"){cout << "N" << endl;}
    else if (s == "E"){cout << "W" << endl;}
    else if (s == "W"){cout << "E" << endl;}
    else if (s == "NE"){cout << "SW" << endl;}
    else if (s == "SW"){cout << "NE" << endl;}
    else if (s == "NW"){cout << "SE" << endl;}
    else if (s == "SE"){cout << "NW" << endl;}

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        solve();

    return 0;
}