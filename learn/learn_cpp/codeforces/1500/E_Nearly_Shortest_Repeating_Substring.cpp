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
    int ans = n;
    for (int i=1;i<n;i++){
        if (n%i == 0){
            int x = n/i;
            int diff = 0;
            bool poss = 1;
            for (int j=0;j<i;j++){
                unordered_map<int, int> mp;
                for (int l=0;l<x;l++){
                    int c = j + l*i;
                    mp[s[c]] += 1;
                }
                // cout << "SIZE: " << mp.size() << endl;
                for (auto ele: mp){
                    // cout << ele.first << " - " << ele.second << endl;
                }
                if (mp.size() > 2){diff += 1;poss=0;break;}
                if (mp.size() == 2){
                    if (diff >= 1){poss = 0;break;}
                    else{
                        if (mp.begin()->second == 1 || (++mp.begin())->second == 1){
                            diff += 1;
                        }else{
                            diff += 1;
                            poss = 0;break;
                        }
                    }
                }
            }
            // cout << i << " " << diff << " " << poss << endl;
            if (poss && diff <= 1){
                ans = i;break;
            }
        }
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