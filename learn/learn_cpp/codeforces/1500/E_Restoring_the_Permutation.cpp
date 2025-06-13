#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace __gnu_pbds;
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<int>::iterator
#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){

    int n;cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    set<int> left;
    for (int i=1;i<=n;i++){
        if (lower_bound(all(a), i) == upper_bound(all(a), i)){
            left.insert(i);
        }
    }
    int last = a[0];
    for (int i=1;i<n;i++){
        if (a[i] == last){
            a[i] = -1;
        }else{
            last = a[i];
        }
    }

    // for min
    auto it = left.begin();
    for (int i=0;i<n;i++){
        if (a[i] == -1){
            cout << *it << " ";
            it++;
        }else{
            cout << a[i] << " ";
        }
    }cout << endl;

    // for max

    for (int i=1;i<n;i++){
        if (a[i] == -1){
            auto it = --(left.lower_bound(a[i-1]));
            a[i] = *it;
            left.erase(it);
        } 
    }

    for (auto ele: a){
        cout << ele << " ";
    }
    cout << endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        solve();

    }

    return 0;
}