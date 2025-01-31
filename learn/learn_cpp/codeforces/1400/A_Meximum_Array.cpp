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
    vi a(n);
    rep(i, n){
        cin >> a[i];
    }
    vector<int> num(n+1, 0);
    rep(i, n){
        num[a[i]] += 1;
    }
    int i = 0;
    vector<int> out;
    while (i < n){
        int f = 0;
        int j = i;
        set<int> temp;
        temp.insert(a[i]);
        while (num[f] > 0 || temp.find(f) != temp.end()){
            if (temp.find(f) != temp.end()){
               f += 1;
            }else{
                 while (a[i] != f){
                    num[a[i]] -= 1;
                    i++;
                    temp.insert(a[i]);
                }
                f+=1;
            }
        }
        // cout << i << " - " << j << endl;
        if (f != 0){
            // int req = 0;
            // for (auto ele: temp){
            //     if (ele == req){
            //         req += 1;
            //     }else{
            //         break;
            //     }
            // }
            // if (f != 0){
                out.push_back(f);
            // }
        }else{
            out.push_back(0);
        }
        num[a[i]] -= 1;
        i++;
    }
    cout << out.size() << endl;
    for (auto ele: out){
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