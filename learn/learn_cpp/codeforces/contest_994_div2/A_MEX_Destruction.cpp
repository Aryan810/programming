#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (int i=0;i<n;i++) cin >> a[i];

    int sum = accumulate(all(a), 0ll);
    if (sum == 0){cout << 0 << endl;return;}
    vi ind;
    for (int i=0;i<n;i++){
        int num = 0;
        while (i < n && a[i] == 0){
            i++;
        }
        while (i < n && a[i] != 0){
            num++;
            i++;
        }
        
        if (num > 0){ind.push_back(num);}
    }

    if (ind.size() >= 2){cout << 2 << endl;}else{cout << ind.size() << endl;}
    

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