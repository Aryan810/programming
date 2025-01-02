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

    int n, k;
    cin >> n >> k;
    
    vector<int> p(n);
    int j = 1;
    int l = 0;
    bool rev = 0;
    while (j <= n){
        if (!rev){
            for (int i=l;i<n;i+=k){
                p[i] = j;
                j+=1;
            }
            rev = 1;
        }else{
            for (int i=(l+((n-1-l)/k)*k);i>=l;i-=k){
                p[i] = j;
                j+=1;
            }
            rev = 0;
        }
        l++;
    }   

    for (auto ele:p){
        cout << ele << " ";
    }cout << endl;

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