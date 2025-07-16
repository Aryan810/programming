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
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){

    ordered_set<int> st;
    st.insert(1);
    st.insert(1);
    st.insert(1);
    st.insert(2);
    st.insert(2);
    st.insert(2);
    st.insert(10);
    st.insert(2);
    st.insert(9);
    st.insert(9);
    st.insert(9);

    for (auto & ele: st){
        cout << ele << " ";
    }cout << endl;

    auto x = st.upper_bound(11);
    if (x != st.end()){
        cout << st.order_of_key(*x) << endl;
    }


}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--){

        solve();

    }

    return 0;
}