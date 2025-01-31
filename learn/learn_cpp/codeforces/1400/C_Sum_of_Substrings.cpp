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

    int n, k;cin >> n >> k;
    string s;
    cin >> s;
    int ones = 0;
    rep(i, n){
        ones += s[i] - '0';
    }

    if (s[0] == '1' && s.back() == '1'){
        cout << (11 + 11*(ones-2)) << endl;
    }else if (s[0] == '1' && s.back() == '0'){
        ones -= 1;
        if (ones == 0){
            if (n-1 <= k){
                cout << 1 << endl;
            }else{
                cout << 10 << endl;
            }
        }else{
            int i=s.size()-2;
            while (i > 0 && s[i] == '0'){
                i--;
            }
            if (s[i] == '1'){
                int min_oper = n-1-i;
                if (min_oper <= k){
                    cout << (11+11*(ones-1)) << endl;
                }else{
                    cout << (10 + 11*ones) << endl;
                }
            }
        }
    }else if (s[0] == '0' && s.back() == '1'){
        ones -= 1;
        if (ones == 0){
            cout << 1 << endl;
        }else{
            int i=1;
            while (i < n && s[i] == '0'){
                i++;
            }
            if (s[i] == '1'){
                int min_oper = i;
                if (min_oper <= k){
                    cout << (11+11*(ones-1)) << endl;
                }else{
                    cout << (1 + 11*ones) << endl;
                }
            }
        }
    }else{
        if (ones == 0){
            cout << 0 << endl;
        }else if (ones == 1){
            int fromstart = 0;
            int fromend = 0;
            int i=1;
            while (i<n && s[i] != '1'){
                i++;
            }
            if (s[i] == '1'){
                fromstart = i;
            }
            i = n-2;
            while (i > 0 && s[i] != '1'){
                i--;
            }
            if (s[i] == '1'){
                fromend = n-1-i;
            }
            if (fromend <= k){
                cout << (1) << endl;
            }else if (fromstart <= k){
                cout << 10 << endl;
            }else{
                cout << 11 << endl;
            }
        }else{
            int fromstart = 0;
            int fromend = 0;
            int i=1;
            while (i<n && s[i] != '1'){
                i++;
            }
            if (s[i] == '1'){
                fromstart = i;
            }
            i = n-2;
            while (i > 0 && s[i] != '1'){
                i--;
            }
            if (s[i] == '1'){
                fromend = n-1-i;
            }
            int ans = 0;
            if (fromend <= k){
                ans += 1;
                ones -= 1;
                k-=fromend;
            }
            if (fromstart <= k){
                ans += 10;
                ones -= 1;
            }
            ans += 11*(ones);
            cout << ans << endl;
        }
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