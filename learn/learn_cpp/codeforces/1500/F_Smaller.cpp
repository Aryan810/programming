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
    vector<int> s(26);
    s[0] += 1;
    vector<int> t(26);
    t[0] += 1;

    rep(i, n){
        int d, k;cin >> d >> k;
        string x;
        cin >> x;
        if (d == 1){
            for (auto ele: x){
                s[ele-'a'] += k;
            }
        }else{
            for (auto ele: x){
                t[ele-'a'] += k;
            }
        }
        // for (auto ele: t){
        //     cout << ele << " ";
        // }cout << endl;
        // for (auto ele: s){
        //     cout << ele << " ";
        // }cout << endl;
        int fs=0, lt=25;
        while (s[fs] == 0){
            fs += 1;
        }
        while (t[lt] == 0){
            lt -= 1;
        }
        // cout << lt << " " << fs << endl;
        if (lt < fs){
            cout << "NO" << endl;
            continue;
        }else if (lt == fs){
            bool thereMore = 0;
            for (int j = fs+1;j<26;j++){
                if (s[j] > 0){
                    thereMore = 1;
                    break;
                }
            }
            if (thereMore){
                cout << "NO" << endl;
                continue;
            }else{
                if (s[fs] >= t[lt]){
                    cout << "NO" << endl;
                    continue;
                }
            }
        }
        cout << "YES" << endl;
    }

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