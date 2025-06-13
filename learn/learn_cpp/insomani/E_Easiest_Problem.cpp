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
    string s;
    cin >> s;

    vector<int> ones;
    vector<int> zeros;

    for (int i=0;i<n;i++){
        if (s[i]=='1'){
            ones.push_back(i);
        }else{
            zeros.push_back(i);
        }
    }

    string out;
    out.push_back(s[0]);
    
    for (int i=1;i<n;i++){

        if (s[i] == out.back()){
            out.push_back(s[i]);
            continue;
        }

        int num = 0;
        int j = i;
        while (j < n && s[j] != out.back()){
            j += 1;
        }

        if (j-i == 1){
            continue;
        }
        if (j-i > 1){
            while (i < j){
                out.push_back(s[i]);
                i += 1;
            }
            i -= 1;
            continue;
        }

        // int last = out.back();
        // auto nxt = lower_bound(s.begin()+i, s.end(), last);
        // if (nxt == s.end()){
        //     while (i < nxt-s.begin()){
        //         out.push_back(s[i]);
        //         i += 1;
        //     }
        //     i -= 1;
        // }
        // if (nxt-s.begin()-i == 0){
        //     out.push_back(s[i]);
        // }else if (nxt-s.begin()-i == 1){
        //     out.push_back(*nxt);
        //     i += 1;
        // }else{
        //     while (i < nxt-s.begin()){
        //         out.push_back(s[i]);
        //         i += 1;
        //     }
        //     i -= 1;
        // }
    }

    int ans = 0;
    for (int i=0;i<out.size()-1;i++){
        if (out[i] == out[i+1]){ans += 1;}
    }
    cout << ans << endl;

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