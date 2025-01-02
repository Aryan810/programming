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
    string a, b;cin >> a >> b;
    vector<pair<int, int> > oper;
    if (a != b){
        for (int i=0;i<n;i++){
            if (a[i]+b[i] != '0'+'1'){
                cout << "NO" << endl;
                return;
            }
        }
        a = b;
        oper.push_back({1, n});
    }

    for (int i=0;i<n-1;i+=2){
        if (a[i] == '1' && a[i+1] == '1'){
            oper.push_back({i+1, i+1});
            oper.push_back({i+2, i+2});
        }else if (a[i] == '1' && a[i+1] == '0'){
            oper.push_back({i+2, i+2});
            oper.push_back({i+1, i+2});
        }else if (a[i] == '0' && a[i+1] == '1'){
            oper.push_back({i+1, i+1});
            oper.push_back({i+1, i+2});
        }
    }
    if (n&1){
        if (a[n-1] == '1' && b[n-1] == '1'){
            oper.push_back({1, n});
            oper.push_back({1, n-1});
        }
    }
    cout << "YES" << endl;
    cout << oper.size() << endl;
    for (auto ele: oper){
        cout << ele.first << " " << ele.second << endl;
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