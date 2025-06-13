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

    int x = accumulate(all(s), -1*(s.size())*'0');
    int g = x-1;
    int ans = 0;

    if (g&1){
        int one = 0;
        int p = g/2;
        int j = 0;
        for (int i=0;i<p+2;i++){
            int z = 0;
            while (j < n && s[j] == '0'){
                z += 1;
                j += 1;
            }
            ans += one * z;
            if (s[j] == '1'){one += 1;}
            j += 1;
        }
        one = 0;
        j = n-1;
        for (int i=0;i<p+1;i++){
            int z = 0;
            while (j >= 0 && s[j] == '0'){
                z += 1;
                j -= 1;
            }
            ans += one * z;
            if (s[j] == '1'){one += 1;}
            j -= 1;
        }
    }else{
        int one = 0;
        int p = g/2;
        int j = 0;
        for (int i=0;i<p+1;i++){
            int z = 0;
            while (j < n && s[j] == '0'){
                z += 1;
                j += 1;
            }
            ans += one * z;
            if (s[j] == '1'){one += 1;}
            j += 1;
        }
        one = 0;
        j = n-1;
        for (int i=0;i<p+1;i++){
            int z = 0;
            while (j >= 0 && s[j] == '0'){
                z += 1;
                j -= 1;
            }
            ans += one * z;
            if (s[j] == '1'){one += 1;}
            j -= 1;
        }
    }
    cout << ans << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve();

    return 0;
}