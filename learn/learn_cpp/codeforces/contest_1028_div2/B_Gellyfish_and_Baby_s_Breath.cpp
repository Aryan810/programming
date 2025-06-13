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
#define umap(x, y) unordered_map<x, y, custom_hash>

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

const int M = 998244353ll;
int power[100000 + 3];

void solve(){

    int n;
    cin >> n;
    vi p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];

    pair<int, int> m1 = {p[0], 0};
    pair<int, int> m2 = {q[0], 0};

    for (int i=0;i<n;i++){
        if (p[i] > m1.first){
            m1.first = p[i];
            m1.second = i;
        }
        if (q[i] > m2.first){
            m2.first = q[i];
            m2.second = i;
        }
        int temp = 0;
        if (m1.first == m2.first){
            if (q[i-m1.second] > p[i-m2.second]){
                temp = max(temp, (power[m1.first] + power[q[i-m1.second]])%M);
            }else{
                temp = max(temp, (power[m2.first] + power[p[i-m2.second]])%M);
            }
        }else if (m1.first > m2.first){
            temp = max(temp, (power[m1.first] + power[q[i-m1.second]])%M);
        }else{
            temp = max(temp, (power[m2.first] + power[p[i-m2.second]])%M);
        }
        cout << temp%M << " ";
        
    }cout << endl;
    

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test;
    cin >> test;
    int temp = 1;
    for (int i=0;i<=100000;i++){
        power[i] = temp;
        temp = (temp * 2)%M;
    }
    while(test--){
        solve();
    }

    return 0;
}