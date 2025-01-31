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
    vi heights(n);
    rep(i, n){
        cin >> heights[i];
    }
    vector<int> left(n, -1), right(n, n);
    stack<int> st;

    // calc -> left part
    for (int i=0;i<n;i++){
        while (!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        if (!st.empty()){
            left[i] = st.top();
        }
        st.push(i);
    }

    // empty stack
    while (!st.empty()){
        st.pop();
    }

    //calc right
    for (int i=n-1;i>=0;i--){
        while (!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        if (!st.empty()){
            right[i] = st.top();
        }
        st.push(i);
    }

    vi res(n, 0);
    for (int i=0;i<n;i++){
        int sz = right[i] - left[i] - 1;
        res[sz-1] = max(res[sz-1], heights[i]);
    }
    for (int i=n-2;i>=0;i--){
        res[i] = max(res[i+1], res[i]);
    }
    for (auto ele: res){
        cout << ele << " ";
    }cout << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve();


    return 0;
}