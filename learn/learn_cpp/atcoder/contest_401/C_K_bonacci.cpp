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
int M = 1e9;

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    if (n < k){
        cout << 1 << endl;return 0;
    }else if (n == k){
        cout << k << endl;return 0;
    }
    int sm = k;
    queue<int> a;
    for (int i=0;i<k;i++){
        a.push(1);
    }

    for (int i=k;i<=n;i++){
        a.push(sm);
        sm = (2*sm - a.front() + M)%M;
        a.pop();
        // cout << a.size() << endl;
    }
    cout << a.back() << endl;


    return 0;
}